#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
 
#define ff(i,a,b) for(int i = a; i <= b; i++)
#define fb(i,b,a) for(int i = b; i >= a; i--)
#define trav(a,x) for (auto& a : x)
 
#define sz(a) (int)(a).size()
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k)  print the k-th smallest number in os(0-based)

const int mod = 1000000007;
const int inf = 1e9 + 5;
const int mxN = 300005; 

int n, q;
int X[mxN];
int Y[mxN];

bool res[mxN];

ll cross(int x1, int y1, int x2, int y2){
    return 1ll * x1 * y2 - 1ll * x2 * y1;
}

int kvadrant(int x, int y){
    if(x > 0 && y >= 0)return 0;
    if(x <= 0 && y > 0)return 1;
    if(x < 0 && y <= 0)return 2;
    if(x >= 0 && y < 0)return 3;
}

struct SegTreeMX{
    int bor[4 * mxN];
    void update(int v, int tl, int tr, int pos, int val){
        if(tl == tr){
            bor[v] = val;
            return;
        }
        int mid = (tl + tr) / 2;
        if(pos <= mid)update(v * 2, tl, mid, pos, val);
        else update(v * 2 + 1, mid + 1, tr, pos, val);
        bor[v] = max(bor[v * 2], bor[v * 2 + 1]);
    }

    int kveri(int v, int tl, int tr, int l, int r){
        if(tl > r || l > tr)return 0;
        if(tl >= l && tr <= r)return bor[v];
        int mid = (tl + tr) / 2;
        return max(kveri(v * 2, tl, mid, l, r), kveri(v * 2 + 1, mid + 1, tr, l, r));
    } 

    // max i iz [l, r], tako da je vre[i] >= X
    int walk_MX(int v, int tl, int tr, int l, int r, int X){
        if(tl > r || l > tr)return 0;
        if(tl >= l && tr <= r){

            if(bor[v] < X)return 0;
            if(tl == tr)return tl;
            int mid = (tl + tr) / 2;
            if(bor[v * 2 + 1] >= X)return walk_MX(v * 2 + 1, mid + 1, tr, l, r, X);
            else return walk_MX(v * 2, tl, mid, l, r, X);

        }
        int mid = (tl + tr) / 2;
        int A = walk_MX(v * 2 + 1, mid + 1, tr, l, r, X);
        if(A == 0)return walk_MX(v * 2, tl, mid, l, r, X);
        else return A; 
    }

    int walk_MN(int v, int tl, int tr, int l, int r, int X){
        if(tl > r || l > tr)return 0;
        if(tl >= l && tr <= r){
            if(bor[v] < X)return 0;
            if(tl == tr)return tl;
            int mid = (tl + tr) / 2;
            if(bor[v * 2] >= X)return walk_MN(v * 2, tl, mid, l, r, X);
            else return walk_MN(v * 2 + 1, mid + 1, tr, l, r, X); 
        }
        int mid = (tl + tr) / 2;
        int A = walk_MN(v * 2, tl, mid, l, r, X);
        if(A == 0)return walk_MN(v * 2 + 1, mid + 1, tr, l, r, X);
        else return A;
    }

}S1, S2;

ll area(int x1, int y1, int x2, int y2, int x3, int y3){
   return abs(1ll*x1*(y2-y3) + 1ll*x2*(y3-y1)+1ll*x3*(y1-y2));
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y){  
   ll A = area (x1, y1, x2, y2, x3, y3);
   if(A == 0)return 0;
   ll A1 = area (x, y, x2, y2, x3, y3);
   ll A2 = area (x1, y1, x, y, x3, y3);
   ll A3 = area (x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}

int ko[mxN];
int point[mxN];

int K[mxN];
int poz[mxN];

pii seg[mxN];

int sp[mxN][20];
int cmb(int i, int j){
    return make_pair(X[i], Y[i]) < make_pair(X[j], Y[j]) ? i : j;
}

int rmq(int l, int r){
    int x = 31 - __builtin_clz(r - l + 1);
    return cmb(sp[l][x], sp[r - (1 << x) + 1][x]);
}

vector<pii> in[mxN];

array<int,3> P[mxN];
void preprocess(){

    ff(i,1,n){

        point[i] = i;
        K[i] = kvadrant(X[i], Y[i]);

        int x = X[i], y = Y[i];
        if(X[i] != 0 && Y[i] != 0){
            int nzd = __gcd(x, y);
            x /= nzd; y /= nzd;
        }
        else x = 0, y = 0;
        P[i] = {x, y, K[i]};        
    }

    sort(point + 1, point + n + 1, [&](int s1, int s2){
        return K[s1] == K[s2] ? 
        cross(X[s1], Y[s1], X[s2], Y[s2]) > 0 : K[s1] < K[s2];
    });

    ff(i,1,n){
        poz[point[i]] = i;
        ko[poz[point[i]]] = point[i];
    }

    ff(i,1,n)sp[i][0] = i;
    for(int j = 1; j <= 19; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            sp[i][j] = cmb(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }


    int j2 = 1, j1 = 1;
    ff(i,1,n){

        if(K[point[i]] == 0)continue;
        if(K[point[i]] == 3)break;

        if(K[point[i]] == 2){

            int x1 = X[point[i]], y1 = Y[point[i]];

            while(j2 < i && cross(X[point[j2]] - x1, Y[point[j2]] - y1, 0 - x1, 0 - y1) > 0){
                j2 += 1;
            }

            seg[point[i]] = {j2, i};
    
        }
        else{

            int x1 = X[point[i]], y1 = Y[point[i]];

            j1 = max(j1, i);
            while(j1 + 1 <= n && cross(X[point[j1 + 1]] - x1, Y[point[j1 + 1]] - y1, 0 - x1, 0 - y1) >= 0){
                j1 += 1;
            }

            seg[point[i]] = {i, j1};       
        }


    }

}

void solve(){

    // ovo ce biti borba

    map<array<int,3>,int> last; int zero = 0;
    ff(i,1,n){
        S1.update(1,1,n,poz[i],i);

        if(X[i] == 0 && Y[i] == 0)zero = i;

        int kontra = (P[i][2] == 0 ? 2 : P[i][2] == 2 ? 0 : P[i][2] == 1 ? 3 : 1);
        if(last.count({P[i][0], P[i][1], kontra}) == 1)S2.update(1,1,n,i,last[{P[i][0], P[i][1], kontra}]);
        last[P[i]] = i;

        for(auto c : in[i]){ 
            int l = c.fi;
            int id = c.se;

            if(zero >= l || S2.kveri(1,1,n,l,i) >= l){
                res[id] = 1;
                continue;
            }

            int a = rmq(l, i);

            if(K[a] == 0 || K[a] == 3)continue;

            int L = seg[a].fi;
            int R = seg[a].se;

            if(K[a] == 2){

                int mn = ko[S1.walk_MN(1,1,n,L,R,l)];;
                if(mn == 0)continue;
                
                int mxL = ko[S1.walk_MX(1,1,n,1,L - 1,l)];
                if(mxL != 0){
                    res[id] = isInside(X[a], Y[a], X[mn], Y[mn], X[mxL], Y[mxL], 0, 0);
                    continue;
                }

                int mxR = ko[S1.walk_MX(1,1,n,R + 1,n,l)];
                if(mxR != 0)res[id] = isInside(X[a], Y[a], X[mn], Y[mn], X[mxR], Y[mxR], 0, 0);

            }
            else{

                int mx = ko[S1.walk_MX(1,1,n,L,R,l)];
                if(mx == 0)continue;

                int mnR = ko[S1.walk_MN(1,1,n,R + 1,n,l)];
                if(mnR != 0){
                    res[id] = isInside(X[a], Y[a], X[mnR], Y[mnR], X[mx], Y[mx], 0, 0);
                    continue;
                }

                int mnL = ko[S1.walk_MN(1,1,n,1,L - 1,l)];
                if(mnL != 0)res[id] = isInside(X[a], Y[a], X[mnL], Y[mnL], X[mx], Y[mx], 0, 0);
            
            }

        }

    }

}

void Resi(int N, int Px, int Py, int *_X, int *_Y, int Q, int *L, int *R, bool *O){
    n = N; q = Q; 
    ff(i,1,n){
        X[i] = _X[i] - Px;
        Y[i] = _Y[i] - Py;
    }

    preprocess(); 
    
    ff(i,1,q){
        int l = L[i];
        int r = R[i];
        in[r].pb({l, i});
    }

    solve();
    
    ff(i,1,q)O[i] = res[i];

}

// int main(){
//     int N, Px, Py;
//     scanf("%i %i %i", &N, &Px, &Py);

//     int *X = new int[N+1], *Y = new int[N+1];
//     for(int i = 1; i <= N; i++){
//         scanf("%i %i", &X[i], &Y[i]);
//     }

//     int Q;
//     scanf("%i", &Q);

//     int *L = new int[Q+1], *R = new int[Q+1];
//     for(int i = 1; i <= Q; i++){
//         scanf("%i %i", &L[i], &R[i]);
//     }

//     bool *O = new bool[Q+1];

//     Resi(N, Px, Py, X, Y, Q, L, R, O);

//     for(int i = 1; i <= Q; i++){
//         if(O[i]){
//             printf("Da\n");
//         }else{
//             printf("Ne\n");
//         }
//     }

//     delete[] X;
//     delete[] Y;
//     delete[] L;
//     delete[] R;
//     delete[] O;

//     return 0;
// }
/*

7 0 0
-3 3
-2 -3
0 -1
1 -4
2 1
4 -2
4 3
1
1 7

8 0 0
-2 -2
-1 -2
3 -1
1 2
-1 3
3 5
4 1
4 0
1
1 8

// probati bojenje sahovski
*/
 
 
 
 
 

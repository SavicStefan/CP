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
const int mxN = 400005; 

int n, m;
array<int,3> edge[mxN];

vector<int> g[mxN];
int indeg[mxN];

int ko[mxN];

int par[mxN];
int findpar(int x){
    return (x == par[x] ? x : par[x] = findpar(par[x]));
}

int timer = 0;
int in[mxN];
int out[mxN];
int cnt[mxN];
int deda[mxN][20];
void dfs(int v, int p){
    in[v] = ++timer; cnt[v] = (sz(g[v]) == 0);
    deda[v][0] = p; ff(i,1,19)deda[v][i] = deda[deda[v][i - 1]][i - 1];
    for(auto u : g[v]){
        dfs(u, v);
        cnt[v] += cnt[u];
    }
    out[v] = timer;
}

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

void Resi(int N, int *A, int M, int *U, int *V, int *W, int *R){
    n = N; m = M; ff(i,1,m)edge[i] = {W[i], U[i], V[i]};

    sort(edge + 1, edge + m + 1);

    ff(i,1,2 * n - 1)par[i] = i;

    int idx = n;
    ff(i,1,m){
        int u = findpar(edge[i][1]);
        int v = findpar(edge[i][2]);
        int w = edge[i][0];
        
        if(u == v)continue;

        idx++; ko[idx] = w;
        g[idx].pb(u); g[idx].pb(v);
        indeg[v] += 1; indeg[u] += 1;

        par[u] = par[v] = par[idx];

    }

    ff(i,1,idx){
        if(indeg[i] == 0)dfs(i, 0);
    }

    // smem da menjam vozila

    vector<pii> vec;
    ff(i,1,n)vec.pb({A[i], i});
    sort(rall(vec));

    for(auto c : vec){
        int i = c.se;

        int v = i;
        fb(j,19,0){
            if(deda[v][j] != 0 && ko[deda[v][j]] <= A[i]){
                v = deda[v][j];
            }
        }

        int mx = max(cnt[v], kveri(1,1,idx,in[v],out[v]));
        R[i] = mx; update(1,1,idx,in[i],mx);


    }

}


// int main(){
//     int N, M;
//     scanf("%i %i", &N, &M);

//     int *A = new int[N + 1];
//     for(int i = 1; i <= N; i++){
//         scanf("%i", &A[i]);
//     }

//     int *U = new int[M + 1], *V = new int[M + 1], *W = new int[M + 1];
//     for(int i = 1; i <= M; i++){
//         scanf("%i %i %i", &U[i], &V[i], &W[i]);
//     }

//     int *R = new int[N + 1];
//     Resi(N, A, M, U, V, W, R);

//     for(int i = 1; i <= N; i++){
//         printf("%i ", R[i]);
//     }
//     printf("\n");

//     delete[] A;
//     delete[] U;
//     delete[] V;
//     delete[] W;
//     delete[] R;

//     return 0;
// }
/*
 
5 7
7 7 7 7 7
1 2 3
1 3 8
2 5 7
4 5 10
1 5 6
2 3 9
3 5 8 
 
// probati bojenje sahovski
*/
 
 
 
 
 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ldb;
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ldb,ldb> pdd;

#define ff(i,a,b) for(int i = a; i <= b; i++)
#define fb(i,b,a) for(int i = b; i >= a; i--)
#define trav(a,x) for (auto& a : x)
 
#define sz(a) (int)(a).size()
#define fi first
#define se second
#define pb push_back
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
const int mxN = 200005; 

int n, Lx, Ly, Bx, By;
array<int,3> niz[mxN];

vector<pii> g[mxN];
int d[mxN];

bool cmp_x(array<int,3> s1, array<int,3> s2){
    return s1[0] < s2[0];
}

bool cmp_y(array<int,3> s1, array<int,3> s2){
    return s1[1] < s2[1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("lasers.in");
    ofstream cout("lasers.out");

    cin >> n >> Lx >> Ly >> Bx >> By;
    ff(i,1,n)cin >> niz[i][0] >> niz[i][1], niz[i][2] = i;

    niz[0] = {Lx, Ly, 0}; niz[n + 1] = {Bx, By, n + 1}; 
    int V = n + 1;

    sort(niz, niz + n + 2, cmp_x);
    ff(i,0,n + 1){
        int j = i;
        while(j + 1 <= n + 1 && niz[j + 1][0] == niz[i][0])j += 1;

        V += 1;
        ff(l,i,j){
            g[niz[l][2]].pb({V, 1});
            g[V].pb({niz[l][2], 0});
        }

        i = j;
    }

    sort(niz, niz + n + 2, cmp_y);
    ff(i,0,n + 1){
        int j = i;
        while(j + 1 <= n + 1 && niz[j + 1][1] == niz[i][1])j += 1;

        V += 1;
        ff(l,i,j){
            g[niz[l][2]].pb({V, 1});
            g[V].pb({niz[l][2], 0});
        }

        i = j;
    }

    ff(i,0,V)d[i] = inf;

    deque<int> dq; dq.push_back(0); 
    d[0] = 0;

    while(sz(dq)){
        int v = dq.front(); dq.pop_front();
        for(auto c : g[v]){
            int u = c.fi;
            int w = c.se;
            if(d[u] > d[v] + w){
                d[u] = d[v] + w;
                if(w == 0)dq.push_front(u);
                else dq.push_back(u);
            }
        }
    }

    cout << (d[n + 1] == inf ? -1 : d[n + 1] - 1) << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

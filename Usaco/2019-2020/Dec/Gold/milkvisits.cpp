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

int n, q;
int niz[mxN];

vector<int> g[mxN];

vector<pii> in[mxN];
array<int,3> upit[mxN];


int d[mxN];
int za[mxN];
int mx[mxN];
int deda[mxN][20];
void dfs(int v, int p){
    deda[v][0] = p;
    ff(i,1,19)deda[v][i] = deda[deda[v][i - 1]][i - 1];

    int tren = mx[niz[v]];
    mx[niz[v]] = d[v];

    for(auto u : g[v]){
        if(u != p){
            d[u] = d[v] + 1;
            dfs(u, v);
        }
    }

    for(auto c : in[v]){
        int X = c.fi;
        int id = c.se;
        za[id] = max(za[id], mx[X]);
    }

    mx[niz[v]] = tren;

}

int LCA(int x, int y){
    if(d[x] < d[y])swap(x, y);
    fb(i,19,0)if((d[x] - d[y]) & (1 << i))x = deda[x][i];
    fb(i,19,0)if(deda[x][i] != deda[y][i])x = deda[x][i], y = deda[y][i];
    return (x == y ? x : deda[x][0]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");

    cin >> n >> q;
    ff(i,1,n)cin >> niz[i];
    ff(i,1,n - 1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ff(i,1,q){
        int A, B, C;
        cin >> A >> B >> C;
        in[A].pb({C, i}); in[B].pb({C, i});
        upit[i] = {A, B, C};
    }

    ff(i,1,n)mx[i] = za[i] = -1;
    dfs(1, 0);

    ff(i,1,q){
        int A = upit[i][0];
        int B = upit[i][1];
        int C = upit[i][2];
        
        int lca = LCA(A, B);
        int D = za[i];

        cout << (d[lca] <= D ? 1 : 0);

    }

    cout << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

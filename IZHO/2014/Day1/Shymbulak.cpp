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
const int mxN = 200005; 

int n;

vector<int> g[mxN];

int par[mxN];
int visited[mxN];
vector<int> cyc;
void dfs1(int v, int p){
    visited[v] = 1; par[v] = p;
    for(auto u : g[v]){
        if(u == p)continue;
        if(!visited[u])dfs1(u, v);
        else{
            if(visited[u] == 1){
                for(int A = v; A != par[u]; A = par[A])cyc.pb(A);
            }
        }
    }
    visited[v] = 2;
}

pll cmb(pll a, pll b){
    if(a.fi == b.fi)return {a.fi, a.se + b.se};
    if(a.fi > b.fi)return a;
    if(a.fi < b.fi)return b;
    assert(false);
}

pll dia = {0, 0};

bool was[mxN];
pll dfs2(int v, int duz){
    pll best = {duz, 1}; was[v] = 1;
    for(auto u : g[v]){
        if(!was[u]){
            pll D = dfs2(u, duz + 1);
            dia = cmb(dia, {best.fi + D.fi - 2 * duz, 1ll * best.se * D.se});
            best = cmb(best, D);
        }
    }
    return best;
}

pll ja[mxN];

pll bor[4 * mxN];
void build(int v, int tl, int tr){
    if(tl == tr){
        bor[v] = {ja[tl].fi - tl, ja[tl].se};
        return;
    }
    int mid = (tl + tr) / 2;
    build(v * 2, tl, mid); build(v * 2 + 1, mid + 1, tr);
    bor[v] = cmb(bor[v * 2], bor[v * 2 + 1]);
}

pll kveri(int v, int tl, int tr, int l, int r){
    if(tl > r || l > tr)return {-inf, 0};
    if(tl >= l && tr <= r)return bor[v];
    int mid = (tl + tr) / 2;
    return cmb(kveri(v * 2, tl, mid, l, r), kveri(v * 2 + 1, mid + 1, tr, l, r));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    ff(i,1,n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs1(1, -1);

    for(auto c : cyc)was[c] = 1;

    int M = sz(cyc);
    ff(i,0,M - 1)ja[i] = dfs2(cyc[i], 0);

    int K = M / 2;
    build(1,0,M - 1);

    ff(i,0,M - 1){
        pii L = kveri(1,0,M - 1,max(0,i - K),i - 1);
        pii R = kveri(1,0,M - 1,min(M - 1, i + K - !(M&1)) + 1,M - 1);
        R.fi += M + i, L.fi += i;

        pii X = cmb(L, R);
        dia = cmb(dia, {X.fi + ja[i].fi, 1ll * X.se * ja[i].se});
    
    }

    cout << dia.se << '\n';

    return 0;
}
/*
 
6
1 2
1 3 
2 4 
4 3 
4 5 
4 6

4
1 2
1 3
1 4
4 3
 
// probati bojenje sahovski
*/
 
 
 
 
 

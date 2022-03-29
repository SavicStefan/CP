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

int n, q;
int niz[mxN];

vector<int> g[mxN];

int timer = 0;
int d[mxN];
int in[mxN];
int out[mxN];
int deda[mxN][20];
void dfs(int v, int p){
    in[v] = ++timer; 
    deda[v][0] = p; ff(i,1,19)deda[v][i] = deda[deda[v][i - 1]][i - 1];
    for(auto u : g[v]){
        if(u != p){
            d[u] = d[v] + 1;
            dfs(u, v);
        }
    }
    out[v] = ++timer;
}

int LCA(int x, int y){
    if(d[x] < d[y])swap(x, y);
    fb(i,19,0)if((d[x] - d[y]) & (1 << i))x = deda[x][i];
    fb(i,19,0)if(deda[x][i] != deda[y][i])x = deda[x][i], y = deda[y][i];
    return (x == y ? x : deda[x][0]);
}

int dud[mxN];
void upd(int x, int val){
    while(x <= mxN){
        dud[x] ^= val;
        x += x&(-x);
    }
}
int query(int x){
    int sum = 0;
    while(x > 0){
        sum ^= dud[x];
        x -= x&(-x);
    }
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("cowland.in");
    ofstream cout("cowland.out");

    cin >> n >> q;
    ff(i,1,n)cin >> niz[i];
    ff(i,1,n - 1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 0);

    ff(i,1,n){
        upd(in[i], niz[i]);
        upd(out[i], niz[i]);
    }

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            int v, x;
            cin >> v >> x;

            upd(in[v], niz[v]);
            upd(out[v], niz[v]);

            niz[v] = x;

            upd(in[v], niz[v]);
            upd(out[v], niz[v]);         

        }

        if(t == 2){
            int u, v;
            cin >> u >> v;

            int A = query(in[u]);
            int B = query(in[v]);
            int lca = LCA(u, v);

            cout << (A ^ B ^ niz[lca]) << '\n';

        }
    }

    return 0;
}
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

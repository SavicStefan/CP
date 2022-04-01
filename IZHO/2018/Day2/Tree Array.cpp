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
 
int n, m, q;
int niz[mxN];
 
vector<int> g[mxN];
 
set<int> s[mxN];
set<int> gde[mxN];
 
int d[mxN];
int deda[mxN][20];
void dfs(int v, int p){
    deda[v][0] = p;
    ff(i,1,19)deda[v][i] = deda[deda[v][i - 1]][i - 1];
    for(auto u : g[v]){
        if(u != p){
            d[u] = d[v] + 1;
            dfs(u, v);
        }
    }
}
 
int LCA(int x, int y){
    if(d[x] < d[y])swap(x, y);
    fb(i,19,0)if((d[x] - d[y]) & (1 << i))x = deda[x][i];
    fb(i,19,0)if(deda[x][i] != deda[y][i])x = deda[x][i], y = deda[y][i];
    return (x == y ? x : deda[x][0]);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> q;
    ff(i,1,n - 1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ff(i,1,m)cin >> niz[i];

    dfs(1, 0);

    ff(i,2,m){
        int lca = LCA(niz[i - 1], niz[i]);
        s[lca].insert(i); 
    }

    ff(i,1,m)gde[niz[i]].insert(i);

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            int pos, val;
            cin >> pos >> val;

            gde[niz[pos]].erase(pos);

            if(pos != 1){
                int lca = LCA(niz[pos - 1], niz[pos]);
                s[lca].erase(pos);
            }

            if(pos != n){
                int lca = LCA(niz[pos], niz[pos + 1]);
                s[lca].erase(pos + 1);
            }

            niz[pos] = val; gde[niz[pos]].insert(pos);

            if(pos != 1){
                int lca = LCA(niz[pos - 1], niz[pos]);
                s[lca].insert(pos);
            }

            if(pos != n){
                int lca = LCA(niz[pos], niz[pos + 1]);
                s[lca].insert(pos + 1);
            }

        }

        if(t == 2){
            int l, r, v;
            cin >> l >> r >> v;

            auto a = s[v].ub(l); 
            if(a != s[v].end() && *a <= r){
                cout << *a - 1 << " " << *a << '\n';
                continue;
            }

            auto b = gde[v].lb(l);
            if(b != gde[v].end() && *b <= r){
                cout << *b << " " << *b << '\n';
                continue;
            } 

            cout << -1 << " " << -1 << '\n';

        }
    }

    return 0;
}
/*
 
5 4 4
1 2
3 1
3 4
5 3
4 5 2 3
2 1 3 1
1 3 5
2 3 4 5
2 1 3 1
 
// probati bojenje sahovski
*/



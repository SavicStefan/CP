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
const ll inf = 1e18 + 5;
const int mxN = 200005; 

int n, m, T;
int niz[mxN];

vector<pii> g[mxN];

int last[mxN];
ll dist[mxN];

vector<int> e[mxN];

ll uk = 0;
ll rez = 0;

int cnt[mxN];
void dfs(int v){
    cnt[v] = niz[v];
    for(auto u : e[v]){
        dfs(u);
        cnt[v] += cnt[u];
    }

    // ako stavim ovde

    ll kol = 1ll * cnt[v] * T + uk - 1ll * cnt[v] * dist[v];
    rez = min(rez, kol);

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("shortcut.in");
    ofstream cout("shortcut.out");

    cin >> n >> m >> T;
    ff(i,1,n)cin >> niz[i];
    ff(i,1,m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    ff(i,1,n)dist[i] = inf;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({dist[1] = 0, 1});
    while(sz(pq)){
        pii v = pq.top(); pq.pop();
        if(dist[v.se] < v.fi)continue;
        for(auto c : g[v.se]){
            int u = c.fi;
            int w = c.se;
            if(dist[u] > v.fi + w){
                pq.push({dist[u] = v.fi + w, u});
                last[u] = v.se;
            }
            else if(dist[u] == v.fi + w)last[u] = min(last[u], v.se);
        }
    }

    uk = 0;
    ff(i,2,n){
        e[last[i]].pb(i);
        uk += 1ll * niz[i] * dist[i];
    }

    rez = uk; dfs(1);

    cout << uk - rez << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

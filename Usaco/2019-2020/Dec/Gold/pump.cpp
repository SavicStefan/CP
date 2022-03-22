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

int n, m;
array<int,4> edge[mxN];

vector<pii> g[mxN];
int dist[mxN];

void dij(int s){
    ff(i,1,n)dist[i] = inf;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({dist[s] = 0, s});
    while(sz(pq)){
        pii v = pq.top(); pq.pop();
        if(dist[v.se] < v.fi)continue;
        for(auto c : g[v.se]){
            int u = c.fi;
            int w = c.se;
            if(dist[u] > w + v.fi){
                pq.push({dist[u] = w + v.fi, u});
            }
        }
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("pump.in");
    ofstream cout("pump.out");

    cin >> n >> m;
    ff(i,1,m){
        int u, v, c, f;
        cin >> u >> v >> c >> f;
        edge[i] = {f, c, u, v};
    }

    sort(edge + 1, edge + m + 1);

    ll rez = 0;
    fb(i,m,1){
        int u = edge[i][2];
        int v = edge[i][3];
        int c = edge[i][1];
        int f = edge[i][0];

        g[u].pb({v, c});
        g[v].pb({u, c});

        dij(1);

        if(dist[n] == inf)continue;

        ldb X = (ldb)f / (ldb)dist[n];
        X *= (double)1e6;

        rez = max(rez, (ll)X);

    }

    cout << rez << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

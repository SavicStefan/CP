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

int n, M, q;
int niz[mxN];

vector<pii> g[mxN];
int indeg[mxN];

int res[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("timeline.in");
    ofstream cout("timeline.out");

    cin >> n >> M >> q;
    ff(i,1,n)cin >> niz[i];
    ff(i,1,q){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        indeg[v] += 1;
    }

    queue<int> q;
    ff(i,1,n){
        if(indeg[i] == 0){
            q.push(i);
        }
        res[i] = niz[i];
    }

    while(sz(q)){
        int v = q.front(); q.pop();
        for(auto c : g[v]){
            int u = c.fi;
            int w = c.se;
            indeg[u] -= 1;
            if(indeg[u] == 0)q.push(u);
            res[u] = max(res[u], res[v] + w);
        }
    }

    ff(i,1,n)cout << res[i] << '\n';

    return 0;
}
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

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
const int mxN = 1005; 

int n, m, C;
int niz[mxN];

vector<int> g[mxN];

int dp[mxN][mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("time.in");
    ofstream cout("time.out");

    cin >> n >> m >> C;
    ff(i,1,n)cin >> niz[i];
    ff(i,1,m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }

    int N = 1000 / C;

    ff(i,1,n)ff(j,0,N)dp[i][j] = -inf;

    queue<int> q; q.push(1);
    dp[1][0] = 0; 

    while(sz(q)){
        int v = q.front(); q.pop();
        for(auto u : g[v]){
            bool ok = 0;
            ff(j,1,N){
                if(dp[u][j] < dp[v][j - 1] + niz[u]){
                    dp[u][j] = dp[v][j - 1] + niz[u];
                    ok = 1;
                }
            }

            if(ok == 1)q.push(u);

        }
    }

    int rez = 0;
    ff(j,0,N)rez = max(rez, dp[1][j] - C * j * j);

    cout << rez << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

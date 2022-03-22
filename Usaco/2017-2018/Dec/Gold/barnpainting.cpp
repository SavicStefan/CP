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

int n, K;

vector<int> g[mxN];

int add(int a, int b){
    a += b;
    if(a >= mod)a -= mod;
    return a;
}
int sub(int a, int b){
    a -= b;
    if(a < 0)a += mod;
    return a;
}
int mul(int a, int b){
    return (1ll * a * b) % mod;
}
int power(int a, int b){
    if(!b)return 1;
    int pola = power(a, b / 2);
    pola = mul(pola, pola);
    if(b % 2 == 1)pola = mul(pola, a);
    return pola;
}
int inv(int a){
    return power(a, mod - 2);
}

int dp[mxN][3];
void dfs(int v, int p){
    for(auto u : g[v]){
        if(u != p){
            dfs(u, v);

           dp[v][0] = mul(dp[v][0], add(dp[u][1], dp[u][2]));
           dp[v][1] = mul(dp[v][1], add(dp[u][0], dp[u][2]));
           dp[v][2] = mul(dp[v][2], add(dp[u][0], dp[u][1]));
            
        }
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("barnpainting.in");
    ofstream cout("barnpainting.out");

    cin >> n >> K;
    ff(i,1,n - 1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ff(i,1,n)ff(j,0,2)dp[i][j] = 1;

    ff(i,1,K){
        int a, b;
        cin >> a >> b;
        ff(j,0,2)dp[a][j] = 0;
        dp[a][b - 1] = 1;
    }

    dfs(1, -1);

    int ans = add(dp[1][0], add(dp[1][1], dp[1][2]));
    cout << ans << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

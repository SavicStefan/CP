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

int n, m, k;
string s;

int cost[26][26];

int dp[mxN];

int pref[mxN][26];
int mn[mxN][26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("cowmbat.in");
    ofstream cout("cowmbat.out");

    cin >> n >> m >> k >> s; s = ' ' + s;
    ff(i,0,m - 1)ff(j,0,m - 1)cin >> cost[i][j];

    ff(k,0,m - 1)ff(i,0,m - 1)ff(j,0,m - 1)cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    ff(i,1,n)ff(j,0,m - 1)pref[i][j] = pref[i - 1][j] + cost[s[i] - 'a'][j];

    ff(i,1,n)dp[i] = inf;

    dp[0] = 0; ff(j,0,m - 1)mn[0][j] = 0;
    ff(i,1,n){

        if(i >= k){
            ff(j,0,m - 1){
                dp[i] = min(dp[i], mn[i - k][j] + pref[i][j]);
            }
        }

        ff(j,0,m - 1)mn[i][j] = min(mn[i - 1][j], dp[i] - pref[i][j]);
    }

    cout << dp[n] << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

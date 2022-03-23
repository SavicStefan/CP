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
const int mxN = 1005; 

int n, m;
pii A[mxN];
pii B[mxN];

ll dp[mxN][mxN][2];

int dist(pii X, pii Y){
    return (X.fi - Y.fi) * (X.fi - Y.fi) + (X.se - Y.se) * (X.se - Y.se);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("checklist.in");
    ofstream cout("checklist.out");

    cin >> n >> m;
    ff(i,1,n)cin >> A[i].fi >> A[i].se;
    ff(i,1,m)cin >> B[i].fi >> B[i].se;

    ff(i,0,n)ff(j,0,m)dp[i][j][0] = dp[i][j][1] = inf;

    // dp[0][0][0] = 0; // 0 - H, 1 - G

    dp[1][0][0] = 0;
    ff(i,0,n){
        ff(j,0,m){
            
            if(i >= 1){
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + dist(A[i], A[i - 1]));
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + dist(A[i], B[j]));
            }

            if(j >= 1){
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dist(B[j], B[j - 1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + dist(B[j], A[i]));
            }

        }
    }

    cout << dp[n][m][0] << '\n';

    return 0;
}
/*

3 1
1 2
0 0 
1 0
0 1

// probati bojenje sahovski
*/
 
 
 
 
 

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
const int mxN = 10001; 

int n, K;
int niz[mxN];

ll dp[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("teamwork.in");
    ofstream cout("teamwork.out");

    cin >> n >> K;
    ff(i,1,n)cin >> niz[i];

    // u svaki tim moze najvise K krava

    dp[0] = 0;
    ff(i,1,n){
        int mx = 0;
        fb(j,i,max(1,i - K + 1)){
            mx = max(mx, niz[j]);
            dp[i] = max(dp[i], dp[j - 1] + 1ll * (i - j + 1) * mx);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

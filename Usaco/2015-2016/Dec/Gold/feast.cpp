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
const int mxN = 5000005; 

int T, A, B;

bool dp[mxN][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("feast.in");
    ofstream cout("feast.out");

    cin >> T >> A >> B;

    // 0

    dp[0][0] = 1;
    ff(i,1,T){
        if(i >= A)dp[i][0] |= dp[i - A][0];
        if(i >= B)dp[i][0] |= dp[i - B][0];
    }

    // 1

    ff(i,1,T){

        dp[i][1] |= dp[2 * i][0] | dp[2 * i + 1][0];

        if(i >= A){
            dp[i][1] |= dp[i - A][1];
        }

        if(i >= B){
            dp[i][1] |= dp[i - B][1];
        }

    }

    fb(i,T,1){
        if(dp[i][0] == 1 || dp[i][1] == 1){
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

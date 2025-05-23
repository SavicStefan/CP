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
#define trav(a,x) for(auto& a : x)
 
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
const int mxN = 100001; 

int n;
int A[mxN];
int K[mxN];

const int L = 10;
pii dp[(1 << L)][(1 << L)][11];

int par[mxN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    ff(i,1,n)cin >> A[i];
    ff(i,1,n)cin >> K[i];

    pii rez = {0, 0};
    ff(i,1,n){
        int ad = A[i] & ((1 << L) - 1);
        int ag = A[i] >> L;

        pii mx = {0, 0};
        ff(mask,0,(1 << L) - 1){
            int k = K[i] - __builtin_popcount(mask & ad);
            if(0 <= k && k <= 10){
                mx = max(mx, dp[mask][ag][k]);
            }
        }

        pii cur = {mx.fi + 1, i}; par[i] = mx.se;

        rez = max(rez, cur);
        ff(mask,0,(1 << L) - 1){
            int k = __builtin_popcount(ag & mask);
            dp[ad][mask][k] = max(dp[ad][mask][k], cur);
        }        

    }

    vector<int> res;
    for(int i = rez.se; i != 0; i = par[i])res.pb(i);

    cout << sz(res) << '\n'; reverse(all(res));
    for(auto c : res)cout << c << " ";
    cout << '\n';

    return 0;
}
/*

4
1 2 3 4 
10 0 1 0

2
8 9
20 0

5
5 3 5 3 5
10 1 20 1 20

// probati bojenje sahovski
*/

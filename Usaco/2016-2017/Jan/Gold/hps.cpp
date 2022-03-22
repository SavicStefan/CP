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
char C[mxN];

int dp[mxN][21][3];

bool win(int X, char C){
    if(C == 'H' && X == 2)return 1;
    if(C == 'P' && X == 1)return 1;
    if(C == 'S' && X == 0)return 1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("hps.in");
    ofstream cout("hps.out");

    cin >> n >> K;
    ff(i,1,n)cin >> C[i];

    ff(i,1,n){
        ff(j,0,K){
            ff(l,0,2){
                dp[i][j][l] = dp[i - 1][j][l] + win(l, C[i]);
                if(j >= 1){
                    ff(o,0,2)dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][o] + win(l, C[i]));
                }
            }
        }
    }

    int rez = 0;
    ff(j,0,K)ff(l,0,2)rez = max(rez, dp[n][j][l]);
    cout << rez << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

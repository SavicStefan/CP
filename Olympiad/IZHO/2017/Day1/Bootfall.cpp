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
const int mxN = 505; 

int n;
int niz[mxN];

const int N = 500 * 500;
ll dp[N + 5];

bool dbr[mxN][N + 5];

int add(int a, int b){ a += b; if(a >= mod)a -= mod; return a; }
int sub(int a, int b){ a -= b; if(a < 0)a += mod; return a; }

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    ff(i,1,n)cin >> niz[i];

    dp[0] = 1;
    ff(i,1,n){
        int X = niz[i];
        fb(j,N,X)dp[j] = add(dp[j], dp[j - X]);
    }

    int uk = 0;
    ff(i,1,n)uk += niz[i];

    if(uk % 2 == 1 || dp[uk / 2] == 0){
        cout << 0 << '\n';
        return 0;
    }

    ff(i,1,n){
        int X = niz[i];
        ff(j,X,N)dp[j] = sub(dp[j], dp[j - X]);
        ff(j,1,N)dbr[i][j] = (dp[j] != 0);
        fb(j,N,X)dp[j] = add(dp[j], dp[j - X]);
    }

    vector<int> res;
    ff(X,1,N){

        bool ok = 1;
        ff(i,1,n){
            int kol = uk - niz[i] + X;
            if(kol % 2 == 1 || dbr[i][kol / 2] == 0){
                ok = 0; break;
            }
        }

        if(ok == 1){
            res.pb(X);
        }

    }

    cout << sz(res) << '\n';
    for(auto c : res)cout << c << " ";
    cout << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 

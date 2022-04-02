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
const int mxN = 2005; 

int n, p, q;
int niz[mxN];

int dp[mxN][mxN];
bool check(int X){
    // ako je w = X

    ff(i,0,n)ff(j,0,p)dp[i][j] = inf;
    dp[0][0] = 0;


    int j_p = 1, j_q = 1;
    ff(i,1,n){

        while(j_p < i && niz[i] - niz[j_p] + 1 > X)j_p += 1;
        while(j_q < i && niz[i] - niz[j_q] + 1 > 2 * X)j_q += 1;

        ff(j,0,p){
            
            dp[i][j] = min(dp[i][j], dp[j_q - 1][j] + 1);

            if(j > 0){
                dp[i][j] = min(dp[i][j], dp[j_p - 1][j - 1]);
            }
        }
    }

    ff(j,0,p)if(dp[n][j] <= q)return 1;

    return 0;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> p >> q;
    ff(i,1,n)cin >> niz[i];

    if(p + q >= n){
        cout << 1 << '\n';
        return 0;
    }

    sort(niz + 1, niz + n + 1);

    int l = 1, r = inf, ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans << '\n';

    return 0;
}
/*
 
3 1 1 
2
11
17

13 3 2 
33
66
99
10
83
68
19
83
93
53
15
66
75
 
// probati bojenje sahovski
*/
 
 
 
 
 

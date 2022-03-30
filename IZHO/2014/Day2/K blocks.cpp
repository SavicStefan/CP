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
const int mxN = 200005; 
 
int n, k;
int niz[mxN];
 
int dp[mxN][105];
int L[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n >> k;
    ff(i,1,n)cin >> niz[i];

    stack<int> stek;
    fb(i,n,1){
        while(sz(stek) && niz[stek.top()] <= niz[i]){
            L[stek.top()] = i + 1; stek.pop();
        }
        stek.push(i);
    }

    while(sz(stek)){
        L[stek.top()] = 1;
        stek.pop();
    }

    ff(i,0,n)ff(j,0,k)dp[i][j] = inf;

    dp[0][0] = 0;
    ff(j,1,k){

        deque<int> dq; 
        ff(i,1,n){

            while(sz(dq) && niz[dq.back()] <= niz[i]){
                dp[i][j] = min(dp[i][j], dp[dq.back()][j] - niz[dq.back()] + niz[i]);
                dq.pop_back();
            }

            dp[i][j] = min(dp[i][j], dp[L[i] - 1][j]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + niz[i]);
            dq.push_back(i);

        }
    }

    cout << dp[n][k] << '\n';
 
    return 0;
}
/*
 
3 1
4 7 9 


5 1
1 2 3 4 5 
 
5 2
1 2 3 4 5
 
// probati bojenje sahovski
*/
 

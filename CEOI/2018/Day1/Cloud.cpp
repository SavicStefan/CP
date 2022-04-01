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
const ll inf = 1e18 + 5;
const int mxN = 2005; 
 
int n, m;
array<int,3> A[mxN];
array<int,3> B[mxN];
 
const int N = 100000;
ll dp[N + 5]; // dp[i] - max ako mi ostane i procesora
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n;
 
    vector<array<int,4>> vec;
    ff(i,1,n){
        int c, f, v;
        cin >> c >> f >> v;
        vec.pb({f, 1, c, v});
    }
 
    cin >> m;
    ff(i,1,m){
        int C, F, V;
        cin >> C >> F >> V;
        vec.pb({F, -1, C, V});
    }
 
    sort(all(vec));
 
    ff(i,0,N + 1)dp[i] = -inf;
    dp[0] = 0;
 
    fb(i,sz(vec) - 1,0){
        
        if(vec[i][1] == 1){
            int c = vec[i][2];
            int v = vec[i][3];
            fb(j,N,0)if(j >= c)dp[j] = max(dp[j], dp[j - c] - v);
        }
        else{
            int C = vec[i][2];
            int V = vec[i][3];
            ff(j,0,N)if(j + C <= N)dp[j] = max(dp[j], dp[j + C] + V);
        }
 
 
    }
 
    ll rez = 0;
    fb(i,N,0)rez = max(rez, dp[i]);
 
    cout << rez << '\n';
 
    return 0;
}
/*
 
4
4 2200 700
2 1800 10
20 2550 9999
4 2000 750
3
1 1500 300
6 1900 1500
3 2400 4550
 
1
5 1 8
2
3 1 10
10 1 10
 
 
4
4 1 700
2 1 10
20 1 9999
4 1 750
3
1 1 300
6 1 1500
3 1 4550
 
// probati bojenje sahovski
*/
 
 
 
 
 

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
const int mxN = 1000005; 

int n, m, k;

int dp[mxN];
int pref[mxN];

int add(int a, int b){
    a += b;
    if(a >= mod)a -= mod;
    return a;
}
int sub(int a, int b){
    a -= b;
    if(a < 0)a += mod;
    return a;
}
int mul(int a, int b){
    return (1ll * a * b) % mod;
}
int power(int a, int b){
    if(!b)return 1;
    int pola = power(a, b / 2);
    pola = mul(pola, pola);
    if(b % 2 == 1)pola = mul(pola, a);
    return pola;
}
int inv(int a){
    return power(a, mod - 2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("spainting.in");
    ofstream cout("spainting.out");

    cin >> n >> m >> k;

    ff(i,1,k - 1){
        dp[i] = power(m, i);
        pref[i] = add(pref[i - 1], dp[i]);
    }
    ff(i,k,n){
        dp[i] = sub(pref[i - 1], pref[i - k]);
        dp[i] = mul(dp[i], m - 1);
        pref[i] = add(pref[i - 1], dp[i]); 
    }

    cout << sub(power(m, n), dp[n]) << '\n';

    return 0;
}
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

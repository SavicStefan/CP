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
const int mxN = 10000005; 

int n, K, L;
int niz[mxN];

ll dp1[mxN];
ll dp2[mxN];

ll delivery(int _N, int _K, int _L, int positions[]){
    n = _N; K = _K; L = _L; ff(i,1,n)niz[i] = positions[i - 1];

    int pola = L / 2;

    ff(i,1,n)dp1[i] = inf;
    dp1[0] = 0;
    
    ff(i,1,n){
        if(niz[i] <= pola){
            dp1[i] = min(dp1[i], dp1[max(0, i - K)] + 2 * niz[i]);
        }
        dp1[i] = min(dp1[i], dp1[max(0, i - K)] + L);

    }


    ff(i,1,n)dp2[i] = inf;
    dp2[n + 1] = 0;

    fb(i,n,1){
        if(niz[i] > pola){
            dp2[i] = min(dp2[i], dp2[min(n + 1, i + K)] + 2 * (L - niz[i]));
        }
        dp2[i] = min(dp2[i], dp2[min(n + 1, i + K)] + L);

    }

    ll rez = inf;
    ff(i,0,n)rez = min(rez, dp1[i] + dp2[i + 1]);

    return rez;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
  
    
  
    return 0;
}
/*
 
3 2 8
1 2 5
 
// probati bojenje sahovski
*/
 
 
 
 
 

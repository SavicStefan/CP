#include "ricehub.h"

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
const int mxN = 100005; 

int n, M; ll B;
int niz[mxN];

ll pref[mxN];

bool check(int X){
    
    ff(i,X,n){
        int L = i - X + 1;
        int R = i;

        int mid = (L + R) / 2;

        ll kol_L = 1ll * niz[mid] * (mid - L) - (pref[mid - 1] - pref[L - 1]);
        ll kol_R = pref[R] - pref[mid] - 1ll * (R - mid) * niz[mid];

        ll uk = kol_L + kol_R;
        if(uk <= B)return 1;

    }

    return 0;

}

int besthub(int _R, int _L, int _X[], ll _B){
    n = _R; M = _L; B = _B; ff(i,1,n)niz[i] = _X[i - 1];

    ff(i,1,n)pref[i] = pref[i - 1] + niz[i];

    int l = 1, r = n, ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return ans;
}


// int main() {
//     cin.tie(0)->sync_with_stdio(0);

//     int _X[] = {1, 2, 10, 12, 14};
//     cout << besthub(5, 20, _X, 6) << '\n';

//     return 0;
// }
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

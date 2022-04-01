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
const int mxN = 500005; 
 
int n;
pll niz[mxN];
 
ll pref[mxN];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n;
    ff(i,1,n)cin >> niz[i].fi >> niz[i].se;
    sort(niz + 1, niz + n + 1);
 
    ff(i,1,n)pref[i] = pref[i - 1] + niz[i].se;
 
    ll rez = niz[1].se; ll mn = -niz[1].fi;
    ff(i,2,n){
        mn = min(mn, pref[i - 1] - niz[i].fi);
        ll kol = pref[i] - mn;
        rez = max(rez, kol - niz[i].fi);
    }
 
    cout << rez << '\n';
 
    return 0;
}
/*
 
3 
2 3
11 2 
4 5
 
15
1543361732 260774320
2089759661 257198921
1555665663 389548466
4133306295 296394520
2596448427 301103944
1701413087 274491541
2347488426 912791996
2133012079 444074242
2659886224 656957044
1345396764 259870638
2671164286 233246973
2791812672 585862344
2996614635 91065315
971304780 488995617
1523452673 988137562
 
6 
4 1 
1 5 
10 3 
9 1 
4 2
5 3
 
3 2
2 3
11 2
4 5
 
// probati bojenje sahovski
*/
 
 
 
 
 

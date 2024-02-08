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
const int inf = 1e9;
const int mxN = 200000; 

int rand(int l, int r){
    return l + rng() % (r - l + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cout << 1 << '\n';

    int n = rand(5, 5);
    cout << n << " " << 5 << '\n';
    ff(i,1,n - 1)cout << rand(1, 10) << " ";
    cout << '\n';
    ff(i,1,n)cout << rand(1, 10) << " ";
    cout << '\n';

    return 0;
}
/*

63
???????????????????????????????????????????????????????????????
0

6
???
0

20 3
999919217 999872790
999993731 999966291
999872310 999987288
999840028 999860031
999814033 999864558
999847462 999837382
999927564 999982026
999895698 999936856
999946505 999834938
999863578 999962500
999952268 999903394
999800537 999929880
999906950 999841369
999990835 999963372
999823960 999828328
999990180 999925927
999906176 999921255
999823244 999947039
999943470 999819044
999918522 999944817
14 17 98448
1 3 98902
6 14 92837

5 826092980300
3 456590632268
4383 2

 
// probati bojenje sahovski
*/
 
 
 
 

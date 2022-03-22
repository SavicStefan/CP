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
const int mxN = 100005; 

int n; ll M;
pii niz[mxN];

bool check(int X){
    ff(i,1,n){
        if(niz[i].se > X)continue;
        int j = i; ll sum = niz[i].fi;
        while(j + 1 <= n && niz[j + 1].se <= X){
            j += 1;
            sum += niz[j].fi;
        }
        if(sum >= M)return 1;
        i = j;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("hayfeast.in");
    ofstream cout("hayfeast.out");

    cin >> n >> M;
    ff(i,1,n)cin >> niz[i].fi >> niz[i].se;

    int l = 0, r = inf, ans = 0;
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



// probati bojenje sahovski
*/
 
 
 
 
 

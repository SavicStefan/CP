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
const int mxN = 100005; 

int n, K;
int niz[mxN];

int pref[mxN];

ll dp[mxN][2];
int put[mxN][201];

struct line{
    ll k, b; int id;
};

struct CHT{
    deque<line> hull;

    ldb cross(line x, line y){
        return (ldb) (x.b - y.b) / (ldb)(y.k - x.k);
    }   

    void add(line x){
        if(sz(hull) >= 1 && (hull.back().k == x.k && hull.back().b == x.b))hull.pop_back();
        while(sz(hull) >= 2 && cross(x, hull.back()) <= cross(hull.back(), hull[sz(hull) - 2])){
            hull.pop_back();
        }
        hull.pb(x);
    }

    pll get(ll x){

        while(sz(hull) > 1 && x >= cross(hull[0], hull[1])){
            hull.pop_front();
        }

        return {1ll * hull[0].k * x + hull[0].b, hull[0].id};

    }

};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> K; K += 1;
    ff(i,1,n)cin >> niz[i], pref[i] = pref[i - 1] + niz[i];

    ff(i,1,n)dp[i][1 & 1] = 1ll * pref[i] * (pref[n] - pref[i]);

    ff(j,2,K){

        CHT cht; 
        ff(i,1,n){

            if(dp[i - 1][(j - 1) & 1] != -inf){
                cht.add({pref[i - 1], dp[i - 1][(j - 1) & 1] - 1ll * pref[i - 1] * pref[n], i - 1});
            }

            if(i >= j){
                pll X = cht.get(pref[i]);
                dp[i][j & 1] = X.fi + 1ll * pref[i] * pref[n] - 1ll * pref[i] * pref[i];
                put[i][j] = X.se;
            }
        }

    }

    cout << dp[n][K & 1] << '\n';

    int cur = n;
    fb(i,K,2)cout << put[cur][i] << " ", cur = put[cur][i];
    cout << '\n';


    return 0;
}
/*
 
7 3 
4 1 3 4 0 2 3
 
// probati bojenje sahovski
*/
 
 
 
 
 

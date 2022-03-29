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

int n;
pii niz[mxN];

pii sufi_mn[mxN];
pii sufi_mx[mxN];

pii pref_mn[mxN];
pii pref_mx[mxN];

ll Solve(){

    sufi_mn[n + 1] = {inf, inf}; sufi_mx[n + 1] = {0, 0};
    fb(i,n,1){
        sufi_mn[i].fi = min(sufi_mn[i + 1].fi, niz[i].fi);
        sufi_mn[i].se = min(sufi_mn[i + 1].se, niz[i].se);
        sufi_mx[i].fi = max(sufi_mx[i + 1].fi, niz[i].fi);
        sufi_mx[i].se = max(sufi_mx[i + 1].se, niz[i].se);
    }

    pref_mn[0] = {inf, inf}; pref_mx[0] = {0, 0};
    ff(i,1,n){
        pref_mx[i].fi = max(pref_mx[i - 1].fi, niz[i].fi);
        pref_mx[i].se = max(pref_mx[i - 1].se, niz[i].se);
        pref_mn[i].fi = min(pref_mn[i - 1].fi, niz[i].fi);
        pref_mn[i].se = min(pref_mn[i - 1].se, niz[i].se);
    }

    ll ans = (ll)3e18;
    ff(i,1,n - 1){
        ll kol = 1ll * (pref_mx[i].fi - pref_mn[i].fi) * (pref_mx[i].se - pref_mn[i].se) + 
        1ll * (sufi_mx[i + 1].fi - sufi_mn[i + 1].fi) * (sufi_mx[i + 1].se - sufi_mn[i + 1].se);
        ans = min(ans, kol);
    }

    return ans;

}

bool cmp(pii s1, pii s2){
    if(s1.se == s2.se)return s1.fi < s2.fi;
    return s1.se < s2.se;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("split.in");
    ofstream cout("split.out");

    cin >> n;
    ff(i,1,n)cin >> niz[i].fi >> niz[i].se;
    sort(niz + 1, niz + n + 1);

    int X_mn = inf, X_mx = 0;
    int Y_mn = inf, Y_mx = 0;
    ff(i,1,n){
        X_mn = min(X_mn, niz[i].fi);
        X_mx = max(X_mx, niz[i].fi);
        Y_mn = min(Y_mn, niz[i].se);
        Y_mx = max(Y_mx, niz[i].se);
    }

    ll ans = Solve();

    sort(niz + 1, niz + n + 1, cmp);

    ans = min(ans, Solve());

    ll rez = 1ll * (X_mx - X_mn) * (Y_mx - Y_mn) - ans;

    cout << rez << '\n';

    return 0;
}
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

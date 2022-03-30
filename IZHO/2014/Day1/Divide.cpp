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
const int mxN = 200005; 

int n;
array<int,3> niz[mxN];

ll E[mxN];
ll G[mxN];

ll dud[mxN];
void upd(int x, ll val){
    while(x <= mxN){
        dud[x] = min(dud[x], val);
        x += x&(-x);
    }
}
ll query(int x){
    ll sum = inf;
    while(x > 0){
        sum = min(sum, dud[x]);
        x -= x&(-x);
    }
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    ff(i,1,n)ff(j,0,2)cin >> niz[i][j];

    ff(i,1,n){
        G[i] = G[i - 1] + niz[i][1];
        E[i] = E[i - 1] + niz[i][2];
    }

    vector<ll> all;
    ff(i,1,n){
        all.pb(E[i] - niz[i][0]);
        all.pb(E[i - 1] - niz[i][0]);
    }

    sort(all(all)); all.erase(unique(all(all)), all.end());

    auto fnd = [&](ll X){
        return lb(all(all), X) - all.begin() + 1;
    };

    ff(i,0,mxN - 1)dud[i] = inf;

    ll rez = 0;
    ff(i,1,n){
        upd(fnd(E[i - 1] - niz[i][0]), G[i - 1]);
        ll kol = G[i] - query(fnd(E[i] - niz[i][0]));
        rez = max(rez, kol);
    }

    cout << rez << '\n';

    return 0;
}
/*
 
4 
0 5 1
1 7 2 
4 4 1 
7 15 1

2
0 4 1
3 5 1
 
// probati bojenje sahovski
*/
 
 
 
 
 

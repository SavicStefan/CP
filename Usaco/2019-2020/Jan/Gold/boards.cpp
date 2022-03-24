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
const int inf = 2e9 + 5;
const int mxN = 200005; 

int n, m;

int dp[mxN];

int dud[mxN];
void upd(int x, int val){
    while(x <= mxN){
        dud[x] = min(dud[x], val);
        x += x&(-x);
    }
}
int query(int x){
    int sum = inf;
    while(x > 0){
        sum = min(sum, dud[x]);
        x -= x&(-x);
    }
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("boards.in");
    ofstream cout("boards.out");

    cin >> m >> n;

    vector<array<int,3>> eve; vector<int> all;
    ff(i,1,n){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        eve.pb({x1, y1, i});
        eve.pb({x2, y2, -i}); 
        all.pb(y1); all.pb(y2);
    }

    eve.pb({0, 0, 0}); all.pb(0);
    eve.pb({m, m, n + 1}); all.pb(m);

    sort(all(all)); all.erase(unique(all(all)), all.end());

    auto fnd = [&](int X){
        return lb(all(all), X) - all.begin() + 1;
    };

    ff(i,0,mxN - 1)dud[i] = inf;

    ff(i,1,n + 1)dp[i] = inf;

    sort(all(eve)); 
    ff(i,0,sz(eve) - 1){
        int X = eve[i][0];
        int Y = fnd(eve[i][1]);
        int id = eve[i][2];

        if(id >= 0)dp[id] = min(dp[id], query(Y) + eve[i][0] + eve[i][1]);
        if(id <= 0)upd(Y, dp[-id] - eve[i][0] - eve[i][1]);

    }

    cout << dp[n + 1] << '\n';

    return 0;
}
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

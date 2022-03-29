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

int n, q;
int niz[mxN];

int res[mxN];

set<int> s;

int pre(int X){
    auto a = s.lb(X); 
    a--; return *a;
}

int nxt(int X){
    auto a = s.lb(X); 
    return *a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");

    cin >> n >> q;

    vector<array<int,3>> eve;

    ff(i,1,n){
        int X;
        cin >> X;
        eve.pb({X, -i, -1});
    }

    ff(i,1,q){
        int S, D;
        cin >> S >> D;
        eve.pb({S, D, i});
    }

    sort(all(eve));

    s.insert(0); s.insert(n + 1);
    multiset<int> ms; ms.insert(n + 1);

    for(auto c : eve){
        if(c[1] > 0){
            int D = c[1];
            int id = c[2];

            res[id] = (*ms.rbegin() <= D);

        }
        else{
            int X = -c[1];

            int L = pre(X);
            int R = nxt(X);

            ms.erase(ms.find(R - L));
            ms.insert(X - L); ms.insert(R - X);

            s.insert(X);

        }

    }

    ff(i,1,q)cout << res[i] << '\n';

    return 0;
}
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

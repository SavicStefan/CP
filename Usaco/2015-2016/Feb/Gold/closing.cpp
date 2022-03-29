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

int n, m;
int ord[mxN];

vector<int> g[mxN];
bool bio[mxN];

int res[mxN];

int par[mxN], sz[mxN];
int findpar(int x){
    return (x == par[x] ? x : par[x] = findpar(par[x]));
}
void unite(int x, int y){
    x = findpar(x), y = findpar(y);
    if(x == y)return;
    if(sz[x] < sz[y])swap(x, y);
    par[y] = x; sz[x] += sz[y];
}
void init(){
    ff(i,1,n){
        par[i] = i;
        sz[i] = 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("closing.in");
    ofstream cout("closing.out");

    cin >> n >> m;
    ff(i,1,m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ff(i,1,n)cin >> ord[i];

    init();
    fb(i,n,1){
        int X = ord[i];

        bio[X] = 1;
        for(auto c : g[X])if(bio[c])unite(X, c);

        res[i] = (sz[findpar(X)] == n - i + 1);

    }

    ff(i,1,n)cout << (res[i] == 1 ? "YES" : "NO") << '\n';

    return 0;
}
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

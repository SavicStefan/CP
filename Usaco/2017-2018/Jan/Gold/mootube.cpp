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

array<int,3> edge[mxN];
array<int,3> upit[mxN];

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

    ifstream cin("mootube.in");
    ofstream cout("mootube.out");

    cin >> n >> q;
    ff(i,1,n - 1){
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {w, u, v};
    }

    ff(i,1,q){
        int k, v;
        cin >> k >> v;
        upit[i] = {k, v, i};
    }

    sort(edge + 1, edge + n); 
    reverse(edge + 1, edge + n); 

    sort(upit + 1, upit + q + 1);
    reverse(upit + 1, upit + q + 1);

    init();

    int j = 1;
    ff(i,1,q){
        int k = upit[i][0];
        int v = upit[i][1];
        int id = upit[i][2];

        while(j < n && edge[j][0] >= k){
            unite(edge[j][1], edge[j][2]);
            j += 1;
        }

        res[id] = sz[findpar(v)] - 1;

    }

    ff(i,1,q)cout << res[i] << '\n';

    return 0;
}
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

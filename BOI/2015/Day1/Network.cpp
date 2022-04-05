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
 
const int mod = 998244353;
const int inf = 1e9 + 5;
const int mxN = 500005;
 
int n;
 
vector<int> g[mxN];
 
int timer = 0;
int in[mxN];
void dfs(int v, int p){
    in[v] = ++timer;
    for(auto u : g[v]){
        if(u != p){
            dfs(u, v);
        }
    }
}
 
bool cmp(int s1, int s2){
    return in[s1] < in[s2];
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n;
    ff(i,1,n - 1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
 
    if(n == 1){
        cout << 1 << '\n';
        cout << 1 << " " << 1 << '\n';
        return 0;
    }
 
    dfs(1, -1);
 
    vector<int> leaf;
    ff(i,1,n)if(sz(g[i]) == 1)leaf.pb(i);
 
    sort(all(leaf), cmp);
 
    cout << (sz(leaf) + 1) / 2 << '\n';
 
    if(sz(leaf) % 2 == 1){
        cout << leaf[0] << " " << leaf.back() << '\n';
        leaf.pop_back();
    }
 
    int K = sz(leaf) / 2;
    for(int i = 0; i + K < sz(leaf); i++){
        cout << leaf[i] << " " << leaf[i + K] << '\n';
    }
 
    return 0;
}
/*
 
 
 
// probati bojenje sahovski
*/
 
 
 
 

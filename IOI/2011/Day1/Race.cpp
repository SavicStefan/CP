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
 
int n, k;
 
vector<pii> g[mxN];
 
int cnt[mxN];
bool visited[mxN];
void dfs_cnt(int v, int p){
    cnt[v] = 1;
    for(auto c : g[v]){
        if(!visited[c.fi] && c.fi != p){
            dfs_cnt(c.fi, v);
            cnt[v] += cnt[c.fi];
        }
    }
}
 
int centroid(int v, int p, int vel){
    for(auto c : g[v]){
        if(c.fi == p || visited[c.fi])continue;
        if(cnt[c.fi] > vel / 2)return centroid(c.fi, v, vel);
    }
    return v;
}
 
const int M = 1e6;
int kol[M + 5];
 
int rez = inf;
vector<pii> cuvaj;
void dfs(int v, int p, int A, int d){
    if(A > k)return;
 
    rez = min(rez, d + kol[k - A]);
 
    cuvaj.pb({A, d});
    for(auto c : g[v]){
        int u = c.fi;
        int w = c.se;
        if(u != p && !visited[u]){
            dfs(u, v, A + w, d + 1);
        }
    }
 
}
 
void decmopose(int v, int p){
    dfs_cnt(v, -1); int cen = centroid(v, -1, cnt[v]);
    visited[cen] = 1;
 
    kol[0] = 0; vector<int> brisi;
    for(auto c : g[cen]){
        int u = c.fi;
        int w = c.se;
        if(u != p && !visited[u]){
            cuvaj.clear(); dfs(u, cen, w, 1);
 
            for(auto c : cuvaj){
                if(kol[c.fi] == inf)brisi.pb(c.fi);
                kol[c.fi] = min(kol[c.fi], c.se);
            }
 
        }
    }
 
    for(auto c : brisi)kol[c] = inf;
 
    for(auto c : g[cen]){
        if(c.fi != p && !visited[c.fi])decmopose(c.fi, cen);
    }
 
}
 
int best_path(int N, int K, int H[][2], int L[]){
    n = N; k = K;
    
    ff(i,0,n - 2){
        int u = H[i][0] + 1;
        int v = H[i][1] + 1;
        int w = L[i];
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
 
    ff(i,0,M)kol[i] = inf;
    decmopose(1, -1);
 
    return (rez == inf ? -1 : rez);
 
}
 
// int main() {
//     cin.tie(0)->sync_with_stdio(0);
 
//     cin >> n >> k;
    
//     int H[n][2], L[n];
//     ff(i,0,n - 2){
//         cin >> H[i][0] >> H[i][1] >> L[i];
//         H[i][0] -= 1; H[i][1] -= 1;
//     }
 
//     cout << best_path(n, k, H, L) << '\n';
 
//     return 0;
// }
/*
 
9 57
2 1 50
3 1 11
4 2 4
5 2 53
6 2 64
7 4 7
8 6 10
9 2 55
 
6 7
0 1 1
0 2 1
1 4 3
1 3 8
4 5 2
 
4 3
0 1 1
1 2 2
1 3 4
 
3 3
0 1 1
1 2 1
 
11 12
0 1 3 
0 2 4
2 3 5
3 4 4
4 5 6 
0 6 3
6 7 2 
6 8 5 
8 9 6 
8 10 7
 
// probati bojenje sahovski
*/
 
 
 
 
 

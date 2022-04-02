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

int n, m;
int S, T;
int A, B;

vector<pii> g[mxN];

ll dist_S[mxN];
ll dist_T[mxN];
ll dist_A[mxN];
ll dist_B[mxN];

void dij(int s, ll dist[]){
    ff(i,1,n)dist[i] = inf;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({dist[s] = 0, s});
    while(sz(pq)){
        pll v = pq.top(); pq.pop();
        if(dist[v.se] < v.fi)continue;
        for(auto c : g[v.se]){
            int u = c.fi;
            int w = c.se;
            if(dist[u] > v.fi + w){
                pq.push({dist[u] = v.fi + w, u});
            }
        }
    }

}

ll rez = inf;
ll dp[mxN];
bool visited[mxN];

void dfs_S(int v){
    visited[v] = 1; dp[v] = dist_B[v];
    for(auto c : g[v]){
        int u = c.fi;
        int w = c.se;
        if(dist_T[v] == w + dist_T[u]){
            if(!visited[u])dfs_S(u);
            dp[v] = min(dp[v], dp[u]);
        }
    }

    rez = min(rez, dist_A[v] + dp[v]);

}

void dfs_T(int v){
    visited[v] = 1; dp[v] = dist_B[v];
    for(auto c : g[v]){
        int u = c.fi;
        int w = c.se;
        if(dist_S[v] == w + dist_S[u]){
            if(!visited[u])dfs_T(u);
            dp[v] = min(dp[v], dp[u]);
        }
    }

    rez = min(rez, dist_A[v] + dp[v]); 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> S >> T >> A >> B;
    ff(i,1,m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    dij(S, dist_S);
    dij(T, dist_T);
    dij(A, dist_A);
    dij(B, dist_B);

    rez = dist_A[B];

    dfs_S(S);
    ff(i,1,n)visited[i] = 0;
    dfs_T(T);

    cout << rez << '\n';


    return 0;
}
/*
 
6 6 
1 6 
1 4 
1 2 1 
2 3 1 
3 5 1 
2 4 3 
4 5 2 
5 6 1

6 5
1 2
3 6
1 2 1000000000 
2 3 1000000000 
3 4 1000000000 
4 5 1000000000 
5 6 1000000000

8 8 
5 7 
6 8 
1 2 2 
2 3 3 
3 4 4 
1 4 1 
1 5 5 
2 6 6 
3 7 7 
4 8 8

5 5 
1 5 
2 3 
1 2 1 
2 3 10 
2 4 10 
3 5 10 
4 5 10

10 15 
6 8
7 9
2 7 12
8 10 17 
1 3 1
3 8 14
5 7 15
2 3 7
1 10 14 
3 6 12 
1 5 10 
8 9 1 
2 9 7 
1 4 1 
1 8 1 
2 4 7
5 6 16
 
// probati bojenje sahovski
*/
 
 
 
 
 

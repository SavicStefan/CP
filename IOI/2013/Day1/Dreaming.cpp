#include "dreaming.h"
 
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
 
int n, m, L;
 
vector<pii> g[mxN];
 
int d[mxN];
bool used[mxN];
 
int par[mxN];
bool visited[mxN];
void dfs(int v, int p){
    par[v] = p; visited[v] = 1; 
    for(auto c : g[v]){
        int u = c.fi;
        int w = c.se;
        if(!visited[u]){
            d[u] = d[v] + w;
            dfs(u, v);
        }
    }
}
 
vector<pii> koji;
void Solve(int s){
 
    vector<int> todo;
 
    queue<int> q; q.push(s); used[s] = 1;
    while(sz(q)){
        int v = q.front(); q.pop();
        todo.pb(v);
        for(auto c : g[v]){
            int u = c.fi;
            int w = c.se;
            if(!used[u]){
                used[u] = 1;
                d[u] = d[v] + w;
                q.push(u);
            }
        }
    }
 
    int A = 0;
    for(auto c : todo)if(d[A] <= d[c])A = c;
 
    d[A] = 0; dfs(A, -1);
 
    int B = 0;
    for(auto c : todo)if(d[B] <= d[c])B = c;
 
    vector<int> put;
    for(int i = B; i != par[A]; i = par[i])put.pb(i);
 
    int uk = d[B]; 
 
    int mn = uk, pref = 0; int ko = put[0];
    ff(i,1,sz(put) - 1){
        uk -= (d[put[i - 1]] - d[put[i]]);
        pref += (d[put[i - 1]] - d[put[i]]);
        
        int mx = max(uk, pref);
 
        if(mx < mn){
            mn = mx;
            ko = put[i];
        }
 
    }
 
    koji.pb({mn, ko});
 
}
 
int dia = 0;
int diametar(int v, int p, int duz = 0){
    int best = duz;
    for(auto c : g[v]){
        int u = c.fi;
        int w = c.se;
        if(u != p){
            int d = diametar(u, v, duz + w);
            dia = max(dia, best + d - 2 * duz);
            best = max(best, d);
        }
    }
    return best;
}
 
int travelTime(int N, int M, int _L, int A[],int B[],int T[]){
    n = N; m = M; L = _L;
 
    ff(i,0,m - 1){
        int u = A[i] + 1;
        int v = B[i] + 1;
        int w = T[i];
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
 
    // imam forest, i sad za svako to stablo nadjem diametar 
    // i polje koje cu da spajam sa ostalima
 
    ff(i,1,n){
        if(!visited[i]){
            Solve(i);
        }
    }
 
    sort(rall(koji));
    int sef = koji[0].se;
    ff(i,1,sz(koji) - 1){
        g[sef].pb({koji[i].se, L});
        g[koji[i].se].pb({sef, L});
    }
 
    diametar(1, -1);
 
    return dia;
 
}
 
// int main() {
//     cin.tie(0)->sync_with_stdio(0);
 
//     int N, M, _L;
//     cin >> N >> M >> _L;
 
//     int A[M], B[M], T[M];
//     ff(i,0,M - 1)cin >> A[i];
//     ff(i,0,M - 1)cin >> B[i];
//     ff(i,0,M - 1)cin >> T[i];
 
//     cout << travelTime(N, M, _L, A, B, T) << '\n';
 
//     return 0;
// }
/*
 
12 8 2
0 8 2 5 5 1 1 10
8 2 7 11 1 3 9 6
4 2 4 3 7 1 5 3
 
18
 
// probati bojenje sahovski
*/
 
 
 
 
 

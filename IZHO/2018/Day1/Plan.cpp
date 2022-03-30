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
const int mxN = 100005; 

int n, m, k, q;
pii upit[mxN];

vector<pii> g[mxN];
bool mark[mxN];

ll dist[mxN];
bool bio[mxN];

int L[mxN];
int R[mxN];
int ans[mxN];

int par[mxN];
int findpar(int x){
    return (x == par[x] ? x : par[x] = findpar(par[x]));
}
void unite(int x, int y){
    x = findpar(x), y = findpar(y);
    par[y] = x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    ff(i,1,m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    cin >> k;
    ff(i,1,k){
        int X;
        cin >> X;
        mark[X] = 1;
    }

    cin >> q;
    ff(i,1,q)cin >> upit[i].fi >> upit[i].se;

    priority_queue<pll,vector<pll>,greater<pll>> pq;
    ff(i,1,n){
        if(mark[i] == 1)pq.push({dist[i] = 0, i});
        else dist[i] = inf;
    }

    while(sz(pq)){
        pii v = pq.top(); pq.pop();
        if(dist[v.se] < v.fi)continue;
        for(auto c : g[v.se]){
            int u = c.fi;
            int w = c.se;
            if(dist[u] > w + v.fi){
                pq.push({dist[u] = w + v.fi, u});
            }
        }
    }

    ff(i,1,q)L[i] = 0, R[i] = inf, ans[i] = 0;

    ff(_,1,30){

        vector<pii> eve;
        ff(i,1,q){
            if(L[i] <= R[i]){
                int mid = (L[i] + R[i]) / 2;
                eve.pb({mid, -i});
            }
        }

        ff(i,1,n){
            eve.pb({dist[i], i});
            bio[i] = 0;
            par[i] = i;
        }

        sort(rall(eve));
        for(auto c : eve){
            if(c.se < 0){
                int u = upit[-c.se].fi;
                int v = upit[-c.se].se;

                if(findpar(u) == findpar(v)){
                    ans[-c.se] = c.fi;
                    L[-c.se] = c.fi + 1;
                }
                else{
                    R[-c.se] = c.fi - 1;
                }

            }
            else{
                bio[c.se] = 1;
                for(auto f : g[c.se]){
                    if(bio[f.fi])unite(f.fi, c.se);
                }
            }
        }

    }

    ff(i,1,q)cout << ans[i] << '\n';

    return 0;
}
/*
 
9 12 
1 9 4 
1 2 5 
2 3 7 
2 4 3 
4 3 6 
3 6 4 
8 7 10 
6 7 5 
5 8 1 
9 5 7 
5 4 12 
6 8 2 
2
4 7 
5 
1 6 
5 3 
4 8 
5 8 
1 5
 
// probati bojenje sahovski
*/
 
 
 
 
 

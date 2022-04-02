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
const int mxN = 30005; 

int n, m;
int B[mxN];
int P[mxN];

vector<pii> g[mxN];
int dist[mxN];

set<int> s[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> m >> n;
    
    int S = 0, T = 0;
    ff(i,0,n - 1){
        int B, P;
        cin >> B >> P;
        if(i == 0)S = B;
        if(i == 1)T = B;
        if(i != 1)s[B].insert(P);
    }

    // desno
    ff(i,0,m - 1){
        for(auto c : s[i]){

            int pos = i + c, cost = 1;
            while(pos < m){
                g[i].pb({pos, cost});
                if(s[pos].count(c) == 1)break;
                pos += c; cost += 1;
            }

        }
    }

    // levo    
    ff(i,0,m - 1){
        for(auto c : s[i]){

            int pos = i - c, cost = 1;
            while(pos >= 0){
                g[i].pb({pos, cost});
                if(s[pos].count(c) == 1)break;
                pos -= c; cost += 1;
            }

        }
    }

    ff(i,0,m - 1)dist[i] = inf;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({dist[S] = 0, S});
    while(sz(pq)){
        pii v = pq.top(); pq.pop();
        if(dist[v.se] < v.fi)continue;
        for(auto c : g[v.se]){
            int u = c.fi;
            int w = c.se;
            if(dist[u] > v.fi + w){
                pq.push({dist[u] = v.fi + w, u});
            }
        }
    }

    cout << (dist[T] == inf ? -1 : dist[T]) << '\n';

    return 0;
}
/*

6 4
4 5
0 3
5 1
4 1

18 10
1 2
0 12
1 17
4 1
3 1
5 13
14 7
5 16
15 6
9 5

51 9
9 1
45 2
42 38
17 9
39 44
35 1
22 41
43 35
3 36
 
22 19
10 10
13 5
1 1
17 17
2 3
3 9
20 22
18 1
3 5
11 16
7 16
2 22
20 4
11 19
7 1
16 1
11 14
8 9
3 18

5 3 
0 2 
1 1 
4 1
 
// probati bojenje sahovski
*/
 
 
 
 
 

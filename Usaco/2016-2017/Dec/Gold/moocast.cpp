#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ldb;
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ldb,ldb> pdd;

#define ff(i,a,b) for(int i = a; i <= b; i++)
#define fb(i,b,a) for(int i = b; i >= a; i--)
#define trav(a,x) for (auto& a : x)
 
#define sz(a) (int)(a).size()
#define fi first
#define se second
#define pb push_back
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
const int mxN = 1005; 

int n;
pii niz[mxN];

int dist(int i, int j){
    return (niz[i].fi - niz[j].fi) * (niz[i].fi - niz[j].fi) + (niz[i].se - niz[j].se) * (niz[i].se - niz[j].se); 
}

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

    ifstream cin("moocast.in");
    ofstream cout("moocast.out");

    cin >> n;
    ff(i,1,n)cin >> niz[i].fi >> niz[i].se;

    vector<array<int,3>> vec;
    ff(i,1,n){
        ff(j,i + 1,n){
            vec.pb({dist(i, j), i, j});
        }
    }

    sort(all(vec)); init();

    int rez = 0;
    for(auto c : vec){
        unite(c[1], c[2]);

        if(sz[findpar(1)] == n){
            rez = c[0];
            break;
        }

    }

    cout << rez << '\n';

    return 0;
}
/*

2
0 0
25000 25000

// probati bojenje sahovski
*/
 
 
 
 
 

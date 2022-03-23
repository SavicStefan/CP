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

int n, m;
int ax, ay;
int bx, by;
string a, b;

int dp[mxN][mxN];

pii A[mxN];
pii B[mxN];

int dist(int x1, int y1, int x2, int y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("radio.in");
    ofstream cout("radio.out");

    cin >> n >> m >> ax >> ay >> bx >> by >> a >> b;
    a = ' ' + a; b = ' ' + b;

    A[0] = {ax, ay};
    ff(i,1,n){
        A[i] = A[i - 1];
        if(a[i] == 'E')A[i].fi += 1;
        if(a[i] == 'W')A[i].fi -= 1;
        if(a[i] == 'N')A[i].se += 1;
        if(a[i] == 'S')A[i].se -= 1;
    }

    B[0] = {bx, by};
    ff(i,1,m){
        B[i] = B[i - 1];
        if(b[i] == 'E')B[i].fi += 1;
        if(b[i] == 'W')B[i].fi -= 1;
        if(b[i] == 'N')B[i].se += 1;
        if(b[i] == 'S')B[i].se -= 1;
    }

    ff(i,0,n)ff(j,0,m)dp[i][j] = inf;

    dp[0][0] = 0;
    ff(i,0,n){
        ff(j,0,m){
            if(j >= 1)dp[i][j] = min(dp[i][j], dp[i][j - 1] + dist(A[i].fi, A[i].se, B[j].fi, B[j].se));
            if(i >= 1)dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist(A[i].fi, A[i].se, B[j].fi, B[j].se));
            if(i >= 1 && j >= 1)dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + dist(A[i].fi, A[i].se, B[j].fi, B[j].se));
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

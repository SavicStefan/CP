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
const int mxN = 5005; 

int n, m, K;
pii niz[mxN];

int dp[mxN];
int rima[mxN];

int cnt[27];
int pd[27][100005];

int add(int a, int b){
    a += b;
    if(a >= mod)a -= mod;
    return a;
}
int sub(int a, int b){
    a -= b;
    if(a < 0)a += mod;
    return a;
}
int mul(int a, int b){
    return (1ll * a * b) % mod;
}
int power(int a, int b){
    if(!b)return 1;
    int pola = power(a, b / 2);
    pola = mul(pola, pola);
    if(b % 2 == 1)pola = mul(pola, a);
    return pola;
}
int inv(int a){
    return power(a, mod - 2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("poetry.in");
    ofstream cout("poetry.out");

    cin >> n >> m >> K;
    ff(i,1,n)cin >> niz[i].fi >> niz[i].se;

    dp[0] = 1;
    ff(j,1,K){
        ff(i,1,n){
            int A = niz[i].fi;
            int B = niz[i].se;

            if(j >= A){ 
                dp[j] = add(dp[j], dp[j - A]);
            }

        }

    }

    ff(i,1,n){
        int A = niz[i].fi;
        int B = niz[i].se;
        rima[B] = add(rima[B], dp[K - A]);
    }

    ff(i,1,m){
        char C;
        cin >> C;
        cnt[C - 'A' + 1] += 1;
    }

    pd[0][0] = 1;
    ff(a,1,26){
        
        if(cnt[a] == 0){
            ff(i,0,m)pd[a][i] = pd[a - 1][i];
            continue;
        }

        ff(i,cnt[a],m){
            if(pd[a - 1][i - cnt[a]] == 0)continue;
            ff(j,1,n){
                pd[a][i] = add(pd[a][i], mul(pd[a - 1][i - cnt[a]], power(rima[j], cnt[a])));
            }
        }
    }

    cout << pd[26][m] << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

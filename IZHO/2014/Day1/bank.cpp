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
const int mxN = 25; 

int n, m;
int A[mxN];
int B[mxN];

bool dp[mxN][(1 << 20)];
int suma[(1 << 20)];

vector<int> vec[20005];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    ff(i,1,n)cin >> A[i];
    ff(i,0,m - 1)cin >> B[i];

    ff(mask,0,(1 << m) - 1){
        int S = 0;
        ff(i,0,m - 1)if(mask & (1 << i))S += B[i];
        vec[S].pb(mask);
    }

    dp[0][0] = 1;
    ff(i,1,n){
        ff(mask,0,(1 << m) - 1){
            if(dp[i - 1][mask] == 0)continue;

            for(auto msk : vec[A[i]]){
                if((msk & mask) == 0){
                    dp[i][mask | msk] = 1;
                }
            }

        }
    }

    ff(mask,0,(1 << m) - 1){
        if(dp[n][mask] == 1){
            cout << "YES" << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';

    return 0;
}
/*
 
1 5
8 
4 2 5 1 3

2 6
9 10
5 4 8 6 3 11
 
// probati bojenje sahovski
*/
 
 
 
 
 

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
const int mxN = 3005; 

int n, m;
string s[mxN];

int O[mxN][mxN];
int I[mxN][mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    ff(i,1,n)cin >> s[i], s[i] = ' ' + s[i];

    ff(i,1,n){
        ff(j,1,m){
            O[i][j] = O[i][j - 1] + (s[i][j] == 'O');
        }
    }

    ff(j,1,m){
        ff(i,1,n){
            I[i][j] = I[i - 1][j] + (s[i][j] == 'I');
        }
    }

    ll rez = 0;
    ff(i,1,n){
        ff(j,1,m){
            if(s[i][j] == 'J'){
                rez += 1ll * (O[i][m] - O[i][j]) * (I[n][j] - I[i][j]);
            }
        }
    }

    cout << rez << '\n';

    return 0;
}
/*
 
3 4 
JOIJ 
JIOO 
IIII

4 4 
JJOO 
JJOO 
IIJO 
IIIJ
 
// probati bojenje sahovski
*/
 
 
 
 
 

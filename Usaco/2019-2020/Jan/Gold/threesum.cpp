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
const int mxN = 5005; 

int n, q;
int niz[mxN];

ll kol[mxN][mxN];

const int N = 2e6;
int cnt[2 * N + 5];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("threesum.in");
    ofstream cout("threesum.out");

    cin >> n >> q;
    ff(i,1,n)cin >> niz[i];

    ff(i,1,n){
        cnt[niz[i] + N] += 1;
        ff(j,i + 2,n){
            int X = niz[i] + niz[j];
            kol[i][j] -= cnt[-X + N];
        }
    }

    fb(i,n,1){
        cnt[niz[i] + N] -= 1;
        ff(j,1,i - 2){
            int X = niz[i] + niz[j];
            kol[j][i] += cnt[-X + N];
        }
    }

    ff(i,1,n){
        ff(j,i + 2,n)kol[i][j] += kol[i][j - 1];
        ff(j,1,n)kol[i][j] += kol[i - 1][j];
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        cout << kol[r][r] - kol[l - 1][r] << '\n';
    }

    return 0;
}
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

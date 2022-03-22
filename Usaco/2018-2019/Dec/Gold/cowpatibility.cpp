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
const int mxN = 1000005; 

const int f[] = {1, -1, 1, -1, 1, -1};

int n;

map<array<int,5>,int> kol;

void subset(int A[5]){
    ff(mask,1,(1 << 5) - 1){
        array<int,5> p = {0, 0, 0, 0, 0}; int j = 0;
        ff(i,0,4)if(mask & (1 << i))p[j++] = A[i];
        kol[p] += 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("cowpatibility.in");
    ofstream cout("cowpatibility.out");

    cin >> n;
    ff(i,1,n){
        int A[5];
        ff(j,0,4)cin >> A[j];
        sort(A, A + 5);
        subset(A);
    }


    ll rez = 1ll * n * (n - 1) / 2; 
    for(auto c : kol){
        int br = 0; ff(i,0,4)if(c.fi[i] != 0)br += 1;
        rez += f[br] * 1ll * c.se * (c.se - 1) / 2;
    }

    cout << rez << '\n';

    return 0;
}
/*

2
1 2 3 4 5
1 2 3 4 5

// probati bojenje sahovski
*/
 
 
 
 
 

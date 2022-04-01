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

int n;
pii niz[mxN];

vector<int> find_subset(int l, int r, vector<int> w){
    n = sz(w); ff(i,1,n)niz[i] = {w[i - 1], i};
    sort(niz + 1, niz + n + 1);

    int L = 0, R = -1;

    ll sum = 0; 
    int j = 1;
    ff(i,1,n){

        sum += niz[i].fi;
        while(j < i && sum > r){
            sum -= niz[j].fi; j += 1;
        }

        if(sum >= l && sum <= r){
            L = j;
            R = i;
            break;
        }

    }

    vector<int> res;
    ff(i,L,R)res.pb(niz[i].se - 1);

    return res;

}

// int main() {
//     cin.tie(0)->sync_with_stdio(0);

    
    
//     return 0;
// }
/*
 
4 15 17
6 8 8 7

4 14 15
5 5 6 6

4 10 20
15 17 16 18
 
// probati bojenje sahovski
*/
 
 
 
 
 

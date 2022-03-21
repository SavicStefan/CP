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
const int mxN = 200005; 

int n;
int niz[mxN];

bool ima[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("cardgame.in");
    ofstream cout("cardgame.out");

    cin >> n;
    ff(i,1,n)cin >> niz[i], ima[niz[i]] = 1;

    multiset<int> A, B;
    ff(i,1,2 * n){
        if(!ima[i]){
            if(sz(B) < n / 2)B.insert(i);
            else A.insert(i);
        }
    }

    int br = 0;
    ff(i,1,n / 2){
        int X = niz[i];
    
        auto a = A.lb(X);
        if(a == A.end()){
            A.erase(A.begin());
        }
        else{
            br += 1; A.erase(a);
        }

    }

    ff(i,n / 2 + 1,n){
        int X = niz[i];

        auto a = B.lb(X);
        if(a == B.begin()){

            B.erase(--B.end());
        }
        else{
            br += 1; a--; B.erase(a);
        }
    }

    cout << br << '\n';

    return 0; 
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

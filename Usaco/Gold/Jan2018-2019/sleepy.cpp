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

bool los[mxN];

int dud[mxN];
void upd(int x, int val){
    while(x <= mxN){
        dud[x] += val;
        x += x&(-x);
    }
}
int query(int x){
    int sum = 0;
    while(x > 0){
        sum += dud[x];
        x -= x&(-x);
    }
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("sleepy.in");
    ofstream cout("sleepy.out");

    cin >> n;
    ff(i,1,n)cin >> niz[i];

    ff(i,1,n){
        int X = niz[i];
        if(query(X) != X - 1)los[i] = 1;
        upd(X, 1);
    }

    int last = 0;
    ff(i,1,n)if(los[i] == 1)last = i;

    if(last == 0){
        cout << 0 << '\n';
        return 0;
    }

    ff(i,1,n)dud[i] = 0;

    ff(i,last + 1,n)upd(niz[i], 1);

    vector<int> res;
    ff(i,1,last){
        int X = niz[i];

        int l = X + 1, r = n, ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(query(mid) - query(X) > 0){
                ans = mid;
                r = mid - 1;                
            }
            else l = mid + 1;
        }

        if(ans == 0)res.pb(n - 1);
        else{
            int A = query(ans - 1) + last - i;
            res.pb(A);
        }

        upd(X, 1);

    }

    cout << sz(res) << '\n';
    ff(i,0,sz(res) - 1){
        if(i > 0)cout << " ";
        cout << res[i];
    }
    cout << '\n';


    return 0;
}
/*

5
2 5 1 4 3

// probati bojenje sahovski
*/
 
 
 
 
 

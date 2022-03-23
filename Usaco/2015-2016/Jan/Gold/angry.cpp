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
const int inf = 1e9;
const int mxN = 50005; 

int n;
int niz[mxN];

bool check_R(int i, int X){
    // ako stavim bombu na i, jacine X, da li ce sve desno unistiti

    int cur = i;
    int j = 1;
    while(cur < niz[n]){
        while(j + 1 <= n && niz[j + 1] <= cur + X)j += 1;
        if(niz[j] == cur)return 0;
        cur = niz[j]; X -= 2;
    }   

    return 1;

}

int find_R(int X){

    int l = niz[1], r = niz[n], ans = niz[1];
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check_R(mid, X)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return ans;

}

bool check_L(int i, int X){
    ff(i,1,n)niz[i] *= -1; 
    reverse(niz + 1, niz + n + 1);
    bool ok = check_R(-i, X);
    reverse(niz + 1, niz + n + 1);
    ff(i,1,n)niz[i] *= -1; 
    return ok;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("angry.in");
    ofstream cout("angry.out");

    cin >> n;
    ff(i,1,n)cin >> niz[i], niz[i] *= 2;
    sort(niz + 1, niz + n + 1);

    int l = 0, r = inf, ans = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;

        int R = find_R(mid);
        if(check_L(R, mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;

    }

    cout << ans / 2 << "." << (ans % 2 == 0 ? 0 : 5) << '\n';

    return 0;
}
/*

5
5 8 3 9 1 

3
2 3 8

// probati bojenje sahovski
*/
 
 
 
 
 

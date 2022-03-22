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

int id[mxN];
bool cmp(int s1, int s2){
    return niz[s1] < niz[s2];
}

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

    ifstream cin("bphoto.in");
    ofstream cout("bphoto.out");

    cin >> n;
    ff(i,1,n)cin >> niz[i];

    ff(i,1,n)id[i] = i;
    sort(id + 1, id + n + 1, cmp);

    int br = 0;
    fb(i,n,1){

        int L = query(id[i]);
        int R = n - i - L;

        if(max(L,R) > 2 * min(L,R))br += 1;

        upd(id[i], 1);

    }

    cout << br << '\n';

    return 0;
}
/*



// probati bojenje sahovski
*/
 
 
 
 
 

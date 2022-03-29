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

    ifstream cin("help.in");
    ofstream cout("help.out");

    cin >> n;
    ff(i,1,n)cin >> niz[i].fi >> niz[i].se;
    sort(niz + 1, niz + n + 1);

    int rez = 0;
    ff(i,1,n){
        int L = niz[i].fi;
        int R = niz[i].se;

        int kol = n - 1 - (query(mxN - 1) - query(L));
        rez = add(rez, power(2, kol));

        upd(R, 1);

    }

    cout << rez << '\n';

    return 0;
}
/*
 

 
// probati bojenje sahovski
*/
 
 
 
 
 

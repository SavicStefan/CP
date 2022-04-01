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
int niz[mxN];
 
set<int> A[mxN];
set<int> B[mxN];
 
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
 
ll count_swaps(vector<int> S){
    n = sz(S); ff(i,1,n)niz[i] = S[i - 1];
 
    ff(i,1,n){
        if(niz[i] > 0)A[niz[i]].insert(i);
        if(niz[i] < 0)B[-niz[i]].insert(i);
    }
 
    ff(i,0,mxN - 1)dud[i] = 0;
 
    ll rez = 0;
    ff(i,1,n){  
        int X = niz[i];
 
        if(X > 0){
            if(A[X].count(i) == 0)continue;
            A[X].erase(i);
            auto pos = B[X].begin(); B[X].erase(pos);
            rez += *pos - i - (query(*pos) - query(i - 1));
            upd(*pos, 1);
        }
        else{
            if(B[-X].count(i) == 0)continue;
            B[-X].erase(i);
            auto pos = A[-X].begin(); A[-X].erase(pos);
            rez += *pos - i - 1 - (query(*pos) - query(i - 1));
            upd(*pos, 1);
        }
 
 
    }
 
 
    return rez;
 
}
 
// int main() {
//     cin.tie(0)->sync_with_stdio(0);
 
//     cin >> n;
//     vector<int> A(n);
//     ff(i,0,n - 1)cin >> A[i];
 
//     cout << count_swaps(A) << '\n';
 
//     return 0;
// }
/*
 
 
 
// probati bojenje sahovski
*/
 
 
 
 
 

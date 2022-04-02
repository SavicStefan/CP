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
const int mxN = 2000005; 

int n, q;

// min, max

int mx[4 * mxN];
int mn[4 * mxN];
int lenj[4 * mxN];

void build(int v, int tl, int tr){
    lenj[v] = -1; mx[v] = mn[v] = 0;
    if(tl == tr)return;
    int mid = (tl + tr) / 2;
    build(v * 2, tl, mid); 
    build(v * 2 + 1, mid + 1, tr);
}

void propagate(int v, int tl, int tr){
    if(lenj[v] != -1){
        mn[v] = mx[v] = lenj[v];
        if(tl != tr){
            lenj[v * 2] = lenj[v];
            lenj[v * 2 + 1] = lenj[v];
        }
        lenj[v] = -1;
    }   
}

// add
void lazyupd_add(int v, int tl, int tr, int l, int r, int val){
    propagate(v, tl, tr);
    if(tl > tr || l > tr || tl > r)return;
    if(tl >= l && tr <= r){

        if(mx[v] <= val){
            lenj[v] = val;
            propagate(v, tl, tr);
            return;
        }

        if(mn[v] >= val){
            return;
        }

    }

    int mid = (tl + tr) / 2;
    lazyupd_add(v * 2, tl, mid, l, r, val); lazyupd_add(v * 2 + 1, mid + 1, tr, l, r, val);
    mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
    mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
}

// rem
void lazyupd_rem(int v, int tl, int tr, int l, int r, int val){
    propagate(v, tl, tr);
    if(tl > tr || l > tr || tl > r)return;
    if(tl >= l && tr <= r){

        if(mn[v] >= val){
            lenj[v] = val;
            propagate(v, tl, tr);
            return;
        }

        if(mx[v] <= val){
            return;
        }

    }

    int mid = (tl + tr) / 2;
    lazyupd_rem(v * 2, tl, mid, l, r, val); lazyupd_rem(v * 2 + 1, mid + 1, tr, l, r, val);
    mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
    mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
}

int get(int v, int tl, int tr, int pos){
    propagate(v, tl, tr);
    if(tl == tr)return mn[v];
    int mid = (tl + tr) / 2;
    if(pos <= mid)return get(v * 2, tl, mid, pos);
    else return get(v * 2 + 1, mid + 1, tr, pos);
}

void buildWall(int _n, int _k, int op[], int left[], int right[], int height[], int finalHeight[]){
    n = _n; q = _k; 

    ff(i,0,q){
        int t = op[i];
        int l = left[i];
        int r = right[i];
        int h = height[i];

        if(t == 1){
            // add
            lazyupd_add(1,0,n - 1,l,r,h);
        }

        if(t == 2){
            // remove
            lazyupd_rem(1,0,n - 1,l,r,h);
        }

    }

    ff(i,0,n - 1)finalHeight[i] = get(1,0,n - 1,i);

}

// int main() {
//     cin.tie(0)->sync_with_stdio(0);

    

//     return 0;
// }
/*
 
10 6
1 1 8 4
2 4 9 1
2 3 6 5
1 0 5 3
1 2 2 5
2 6 7 0

 
// probati bojenje sahovski
*/
 
 
 
 
 

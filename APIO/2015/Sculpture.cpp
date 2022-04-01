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
const int mxN = 2005; 

int n, A, B;
int niz[mxN];

bool dp[mxN][mxN];
int pd[mxN];
bool check(ll msk){
    // da li imam resenje tako da je svaki bit iz mask

    if(A == 1){

        // minimalno grupa tako da nema grupa sa msk

        ff(i,0,n)pd[i] = inf;

        pd[0] = 0;
        ff(i,1,n){
            ll X = 0;
            fb(j,i,1){
                X += niz[j];
                if((X & msk) == X){
                    pd[i] = min(pd[i], pd[j - 1] + 1);
                }
            }
        }

        return (pd[n] <= B);

    }

    ff(i,0,n)ff(j,0,B)dp[i][j] = 0;


    dp[0][0] = 1;
    ff(i,1,n){
        ff(j,1,B){
            ll X = 0;
            fb(l,i,1){
                X += niz[l];
                if((X & msk) == X){
                    dp[i][j] |= dp[l - 1][j - 1];
                }
            }
        }
    }

    ff(j,A,B)if(dp[n][j] == 1)return 1;
    return 0;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> A >> B;
    ff(i,1,n)cin >> niz[i];

    // znaci ja hocu da or bude minimalan

    ll rez = (1ll << 41) - 1;
    fb(i,40,0){

        if(check(rez ^ (1ll << i))){
            rez ^= (1ll << i);
        }

    }

    cout << rez << '\n';

    return 0;
}
/*
 
6 1 3 
8 1 2 1 5 4
 
// probati bojenje sahovski
*/
 
 
 
 
 

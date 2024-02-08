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

int n, m;
int A[mxN];
int B[mxN];

int poz[mxN];
int cnt[mxN];

void Solve(){
    cin >> n >> m;
    ff(i,1,n - 1)cin >> A[i];
    ff(i,1,n)cin >> B[i];
    
    sort(A + 1, A + n);
    sort(B + 1, B + n + 1);

    ff(i,1,n + 1)cnt[i] = 0;

    int j = 1;
    ff(i,1,n - 1){
        while(j <= n && B[j] <= A[i])j += 1;
        if(j <= n)cnt[j] += 1;
        poz[i] = j; j = min(j + 1, n + 1);
    }

    ff(i,1,n)cnt[i] += cnt[i - 1];

    int ans = n; 
    ff(i,1,n - 1)ans -= (poz[i] != n + 1);

    A[0] = 1; A[n] = inf; poz[n] = n + 1;

    int last = n;
    ff(i,1,n){
        if(cnt[i] - cnt[i - 1] == 0){
            last = i;
        }
    }

    ll rez = 0;
    ff(i,(A[1] == 1),n - 1){
        if(A[i] > m)break;

        if(poz[i] == n + 1){
            rez += 1ll * (m - A[i] + 1) * ans;
            break;
        }

        int j = i;
        while(j + 1 < n && A[j + 1] == A[j])j += 1;

        int l = A[i];
        int r = min(m, A[j + 1] - 1);
        if(l > m)continue;

        if(poz[j + 1] == n + 1){

            if(cnt[n] - cnt[n - 1] == 1){
                rez += (r - l + 1) * ans;
            }
            else{

                int X = min(r + 1, B[n]);
                rez += 1ll * max(0, X - l) * (ans - 1) + 1ll * (r - X + 1) * ans;

            }


        }
        else{
            // ovo nije tacno


            if(i == 0){
                if(poz[j + 1] == 1){
                    rez += 1ll * (r - l + 1) * (ans - 1);
                }
                else{

                    if(n - poz[j + 1] + 1  > cnt[n] - cnt[poz[j + 1] - 1]){
                        int X = min(r + 1, B[last]);
                        rez += 1ll * max(0, X - l) * (ans - 1) + 1ll * (r - X + 1) * ans;
                    }
                    else{
                        int X = min(r + 1, B[poz[j + 1] - 1]);
                        rez += 1ll * max(0, X - l) * (ans - 1) + 1ll * (r - X + 1) * ans;
                    }

                }


            }
            else{

                if(n - poz[j] > cnt[n] - cnt[poz[j]]){
                    int X = min(r + 1, B[last]);
                    rez += 1ll * max(0, X - l) * (ans - 1) + 1ll * (r - X + 1) * ans;
                }
                else{
                    rez += 1ll * (r - l + 1) * ans;
                }

            }   

        }

        i = j;

    }

    cout << rez << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while(t--)Solve();

    return 0;
}
/*
 

2 1
1
3 2
 
// probati bojenje sahovski
*/
 
 
 
 
 

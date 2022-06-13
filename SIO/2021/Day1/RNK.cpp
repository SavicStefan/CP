#include "code.h"
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



// const int N = 100005;
// char rna[N]; int n;
// int prefix[N][4];

// int toidx(char c) {
//     if(c >= 'a' && c <= 'z') c += 'A' - 'a';
//     return
//         (c == 'A') ? 0 :
//         (c == 'U') ? 1 :
//         (c == 'C') ? 2 :
//         (c == 'G') ? 3 : -1;
// }

// int q, nq;
// int Skener(int L, int R, char C) {
//     if(++nq > q) exit(1);

//     int i = toidx(C);
//     L--; R--;
//     if(L < 0 || L >= n || R < 0 || R >= n || R < L || i == -1) {
//         return 0;
//     }

//     return prefix[R][i] - (L ? prefix[L - 1][i] : 0);
// }



int A[mxN];
void Resi(int N, int *L, int *R) {
    // primer pitanja

    // if(uk_A <= N / 2 && uk_U <= N / 2 && uk_C <= N / 2 && uk_G <= N / 2){
    //     *L = 1; *R = N;
    //     return;
    // }

    int uk_A = Skener(1, N, 'A');

    int ost = 0; char C;
    if(uk_A > N / 2){
        int uk_U = Skener(1, N, 'U');
        C = 'A'; ost = uk_A - N / 2;
        if(ost + uk_U > N / 2){
            *L = -1; *R = -1;
            return;
        }
    }
    else{
        int uk_U = Skener(1, N, 'U');

        if(uk_U > N / 2){
            int uk_A = Skener(1, N, 'A');
            C = 'U'; ost = uk_U - N / 2;
            if(ost + uk_A > N / 2){
                *L = -1; *R = -1;
                return;
            }
        }
        else{
            int uk_C = Skener(1, N, 'C');

            if(uk_C > N / 2){
                int uk_G = N - uk_A - uk_U - uk_C;
                C = 'C';  ost = uk_C - N / 2;
                if(ost + uk_G > N / 2){
                    *L = -1; *R = -1;
                    return;
                }
            }
            else{
                int uk_G = N - uk_A - uk_U - uk_C;

                if(uk_G > N / 2){
                    C = 'G'; ost = uk_G - N / 2;
                    if(ost + uk_C > N / 2){
                        *L = -1; *R = -1;
                        return;
                    }
                }
                else{
                    *L = 1; *R = N;
                }

            }


        }


    }


    char F = C == 'A' ? 'U' : 
             C == 'U' ? 'A' :
             C == 'C' ? 'G' :
             'C';
    
    int puta = 3;

    int l = 1, r = N - 5, ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(puta + 2 > 36)break;
        puta += 2;
        if(Skener(1, mid, C) - Skener(1, mid, F) >= ost){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    if(ans == 0){
        *L = -1; *R = -1;
    }
    else{
        *L = 1; *R = ans;
    }

}


// int main(int argc, char *argv[]) {
//     scanf("%d %d", &n, &q);
//     scanf(" %s", &rna);
 
//     for(int i = 0; i < n; i++) {
//         for(int c = 0; c < 4; c++) {
//             prefix[i][c] = i ? prefix[i - 1][c] : 0;
//         }
//         prefix[i][toidx(rna[i])]++;
//     }

//     int L, R;
//     Resi(n, &L, &R);
//     printf("%d %d\n", L, R);
//     printf("%d\n", nq);

//     return 0;
// }
/*

20 1000
AAAACAAAGAAAAAAUAAAA

11 1000
AAAAAAAAAAU


*/

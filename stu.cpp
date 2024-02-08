#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define pb push_back
#define si(x) int(x.size())
#define all(x) x.begin(), x.end()
#define fi first
#define se second

const int N = 100000;

int a[N+5], b[N+5];

void solve(){
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> vec;
    for(int i=2; i<=n; i++){
        cin >> a[i];
        vec.pb({a[i], 1});
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
        vec.pb({b[i], -1});
    }
    int max_matched = 0;
    sort(all(vec));
    ll res = 0;
    int t = 0;
    for(auto c : vec){
        t += c.se;
        if(t == -1){
            res += m;
            res -= min(m, c.fi - 1) - max_matched;
            max_matched = min(m, c.fi - 1); 
            t++;
        }
        /*if(t < -1){
            t++;
            res += m;
        }*/
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
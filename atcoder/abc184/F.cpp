/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Programming Contest

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> A(n);
    for (auto &z : A) cin >> z;
    
    int x = n / 2;
    int y = n - x;
    
    vector<ll> B((1 << x), 0LL);
    for (int mask = 0; mask < (1 << x); mask++) {
        for (int bit = 0; bit < x; bit++) {
            if (mask & (1 << bit)) {
                B[mask] += A[bit];
            }
        }
    }
    
    vector<ll> C((1 << y), 0LL);
    for (int mask = 0; mask < (1 << y); mask++) {
        for (int bit = 0; bit < y; bit++) {
            if (mask & (1 << bit)) {
                C[mask] += A[x + bit];
            }
        }
    }
    
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    
    ll ans = 0;
    for (auto z : B) {
        if (t < z) continue;
        int need = t - z;
        ans = max(ans, z + *prev(upper_bound(C.begin(), C.end(), need)));
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}
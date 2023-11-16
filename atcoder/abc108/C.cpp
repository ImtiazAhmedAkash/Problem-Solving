/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Triangular Relationship

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
    int n, k;
    cin >> n >> k;
    vector<int> freq(k);
    for (int i = 1; i <= n; i++) {
        freq[i % k]++;
    }
    ll ans = 1LL * freq[0] * freq[0] * freq[0];
    if (~k & 1) {
        int m = k / 2;
        ans += 1LL * freq[m] * freq[m] * freq[m];
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
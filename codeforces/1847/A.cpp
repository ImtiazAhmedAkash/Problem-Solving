/*  In the Name of ALLAH, the most gracious, the most merciful  */

// The Man who became a God

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b;
    for (auto &i : a) cin >> i;
    for (int i = 1; i < n; i++) {
        int x = abs(a[i] - a[i - 1]);
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n - k; i++) ans += b[i];
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
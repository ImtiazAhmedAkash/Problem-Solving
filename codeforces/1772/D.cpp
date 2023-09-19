/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Absolute Sorting

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ans = max(ans, (a[i - 1] + a[i] + 1) / 2);
        }
    }
    for (auto &x : a) {
        x = abs(x - ans);
    }
    if (is_sorted(a.begin(), a.end())) {
        cout << ans << nl;
    } else {
        cout << -1 << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
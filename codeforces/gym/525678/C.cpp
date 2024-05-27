/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Need More Cuet-Bus

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
    int n;
    cin >> n;
    int tot = 0;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tot += x;
        A[i] = {y, x};
    }

    sort(A.begin(), A.end());

    int ans = 0;
    int cur = 0;
    for (auto [y, x] : A) {
        cur += x;
        ans = max(ans, y);
        if (tot <= 2LL * cur) break;
    }
    cout << ans << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// MEDIANT - Unmedian

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
    vector<int> A(n);
    int mx = 0, mn = inf;
    for (auto &x : A) {
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    }

    if (mx == mn) {
        cout << 0 << nl;
        return;
    }

    int last_max = 0, last_min = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == mx) {
            last_max = i;
        }
        if (A[i] == mn) {
            last_min = i;
        }
    }

    if (last_max < last_min) {
        cout << -1 << nl;
        return;
    }

    last_min++;

    vector<pair<int, int>> ans;
    int k = (n - last_min + 1) - 2;
    while (k--) {
        ans.push_back({last_min, last_min + 2});
    }

    while (last_min > 1) {
        ans.push_back({last_min - 1, last_min + 1});
        last_min--;
    }

    cout << ans.size() << nl;
    for (auto &[x, y] : ans) {
        cout << x << " " << y << nl;
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
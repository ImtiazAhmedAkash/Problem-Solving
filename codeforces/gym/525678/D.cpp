/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Save Friendship!!!

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
    vector<int> A(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pref[i] = pref[i - 1] ^ A[i];
    }

    if (all_of(A.begin(), A.end(), [&](int x) { return x == 0; })) {
        cout << -1 << nl;
        return;
    }

    int ans = -1;
    for (int i = k; i <= n; i++) {
        int cur = pref[i] ^ pref[i - k];
        if (cur == 0) continue;

        bool ok = false;
        for (int bit = __lg(cur); bit >= 0; bit--) {
            if (cur & (1 << bit)) continue;
            cur |= (1 << bit);
            ok = true;
            break;
        }
        if (not ok) {
            cur ^= 1;
        }
        ans = max(ans, cur);
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
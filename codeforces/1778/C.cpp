/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Flexible String

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
    string a, b;
    cin >> a >> b;

    vector<int> freq(26);
    for (auto &c : a) {
        freq[c - 'a']++;
    }

    vector<char> C;
    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            C.push_back('a' + i);
        }
    }

    int m = C.size();
    ll ans = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        if (k < __builtin_popcount(mask)) continue;

        vector<bool> good(26);
        for (int bit = 0; bit < m; bit++) {
            if (mask & (1 << bit)) {
                good[C[bit] - 'a'] = true;
            }
        }

        int cnt = 0;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i] || good[a[i] - 'a']) {
                cnt++;
                cur += cnt;
            } else {
                cnt = 0;
            }
        }
        ans = max(ans, cur);
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
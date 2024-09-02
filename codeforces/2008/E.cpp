/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Alternating String

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '-' + s;

    vector even(n + 1, vector<int>(26));
    auto odd = even;

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            odd[i][s[i] - 'a']++;
        } else {
            even[i][s[i] - 'a']++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            even[i][j] += even[i - 1][j];
            odd[i][j] += odd[i - 1][j];
        }
    }

    if (n % 2 == 0) {
        int mx1 = 0, mx2 = 0;
        for (int i = 0; i < 26; i++) {
            mx1 = max(mx1, even[n][i]);
            mx2 = max(mx2, odd[n][i]);
        }
        cout << n - (mx1 + mx2) << nl;
    } else {
        int ans = inf;
        for (int i = 1; i <= n; i++) {
            int mx1 = 0, mx2 = 0;
            for (int j = 0; j < 26; j++) {
                mx1 = max(mx1, even[i - 1][j] + (odd[n][j] - odd[i][j]));
                mx2 = max(mx2, odd[i - 1][j] + (even[n][j] - even[i][j]));
            }
            ans = min(ans, n - (mx1 + mx2));
        }

        cout << ans << nl;
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
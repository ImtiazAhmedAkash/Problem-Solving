/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Two Colored Dominoes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool ok = true;
    int cur = 0;
    string col = "WB";
    for (int i = 0; i < n; i++) {
        cur = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'U') {
                a[i][j] = col[cur % 2];
                cur++;
                a[i + 1][j] = col[cur % 2];
            }
        }
        if (cur & 1) ok = false;
    }
    for (int j = 0; j < m; j++) {
        cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 'L') {
                a[i][j] = col[cur % 2];
                cur++;
                a[i][j + 1] = col[cur % 2];
            }
        }
        if (cur & 1) ok = false;
    }
    if (ok) {
        for (auto x : a) cout << x << nl;
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
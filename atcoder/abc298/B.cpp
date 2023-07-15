/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Coloring Matrix

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n)), c(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> b[i][j];
    }

    for (int r = 0; r < 4; r++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) c[i][j] = a[n - 1 - j][i];
        }

        a = c;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1 && a[i][j] != b[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) {
            cout << "Yes" << nl;
            return;
        }
    }
    cout << "No" << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
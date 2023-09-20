/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Fill in the Matrix

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
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 0 << nl;
        for (int i = 0; i < n; i++) cout << 0 << nl;
        return;
    }
    vector a(n, vector(m, 0));
    if (n >= m) {
        cout << m << nl;
        int x = n - m + 1;
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = j;
            }
        }
        for (int j = 0; j < m; j++) {
            int cur = (a[x][j] + 1) % m;
            for (int i = x + 1; i < n; i++) {
                a[i][j] = cur;
                cur = (cur + 1) % m;
            }
        }
    } else {
        cout << n + 1 << nl;
        for (int i = 0, j = 0; j < m; j++) {
            a[i][j] = j;
        }
        for (int j = 0; j <= n; j++) {
            int cur = (a[0][j] + 1) % (n + 1);
            for (int i = 1; i < n; i++) {
                a[i][j] = cur;
                cur = (cur + 1) % (n + 1);
            }
        }
        for (int j = n + 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                a[i][j] = a[i - 1][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << nl;
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
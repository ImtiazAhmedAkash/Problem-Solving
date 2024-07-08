/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Corner Twist

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
    int n, m;
    cin >> n >> m;
    vector<string> S(n), T(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    for (int i = 0; i < n; i++) {
        int x = 0;
        int y = 0;
        for (int j = 0; j < m; j++) {
            x += S[i][j] - '0';
            y += T[i][j] - '0';
        }
        if (x % 3 != y % 3) {
            cout << "NO" << nl;
            return;
        }
    }

    for (int j = 0; j < m; j++) {
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; i++) {
            x += S[i][j] - '0';
            y += T[i][j] - '0';
        }
        if (x % 3 != y % 3) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;
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
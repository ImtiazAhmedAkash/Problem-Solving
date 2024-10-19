/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Spiral Rotation

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
    vector A(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    auto rotate = [&](int i) -> void {
        for (int j = i; j < n - i + 1; j++) {
            char x = A[i][j];
            A[i][j] = A[n + 1 - j][i];
            A[n + 1 - j][i] = A[n + 1 - i][n + 1 - j];
            A[n + 1 - i][n + 1 - j] = A[j][n + 1 - i];
            A[j][n + 1 - i] = x;
        }
    };

    for (int i = 1; i <= n / 2; i++) {
        int k = i % 4;
        while (k--) {
            rotate(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << A[i][j];
        }
        cout << nl;
    }
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
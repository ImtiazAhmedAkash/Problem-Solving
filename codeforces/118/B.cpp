/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Present from Lena

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

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2 * (n - i); j++) {
            cout << ' ';
        }

        for (int j = 0; j <= i; j++) {
            cout << j;
            if (j != i) cout << ' ';
        }

        for (int j = i - 1; j >= 0; j--) {
            cout << ' ' << j;
        }
        cout << nl;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2 * (n - i); j++) {
            cout << ' ';
        }

        for (int j = 0; j <= i; j++) {
            cout << j;
            if (j != i) cout << ' ';
        }

        for (int j = i - 1; j >= 0; j--) {
            cout << ' ' << j;
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
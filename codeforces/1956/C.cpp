/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Nene's Magical Matrix

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
    int max_sum = 0;
    for (int i = 1, cnt = 1; i <= n; i++, cnt += 2) {
        max_sum += cnt * i;
    }
    cout << max_sum << " " << 2 * n << nl;
    for (int i = n; i > 0; i--) {
        cout << 1 << " " << i;
        for (int j = 1; j <= n; j++) {
            cout << " " << j;
        }
        cout << nl;
        cout << 2 << " " << i;
        for (int j = 1; j <= n; j++) {
            cout << " " << j;
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
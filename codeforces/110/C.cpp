/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Lucky Sum of Digits

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void solve() {
    int n;
    cin >> n;
    for (int i = 6; i >= 0; i--) {
        if (4 * i <= n && (n - 4 * i) % 7 == 0) {
            for (int j = 0; j < i; j++) cout << '4';
            int x = (n - 4 * i) / 7;
            for (int j = 0; j < x; j++) cout << '7';
            cout << nl;
            return;
        }
    }
    cout << -1 << nl;
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
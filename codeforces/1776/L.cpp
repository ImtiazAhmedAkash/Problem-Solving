/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Controllers

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
    string s;
    cin >> s;
    int x = count(s.begin(), s.end(), '+');
    int y = n - x;
    if (x > y) swap(x, y);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);

        int L = 0, R = min((ll)x, 1LL * b * y / a);
        bool ok = false;
        while (L <= R) {
            int M = L + (R - L) / 2;
            ll res = 1LL * M * a - 1LL * (y - (x - M)) * b;
            if (res == 0) {
                ok = true;
                break;
            } else if (res < 0) {
                L = M + 1;
            } else {
                R = M - 1;
            }
        }
        cout << (ok ? "YES" : "NO") << nl;
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
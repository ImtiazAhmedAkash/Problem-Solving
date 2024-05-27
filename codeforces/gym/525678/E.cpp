/*  In the Name of ALLAH, the most gracious, the most merciful  */

// BitMasters Challenge

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
    int g, h, i, j;
    cin >> g >> h >> i >> j;
    int a = 0, b = 0, c = 0;

    for (int bit = 29; bit >= 0; bit--) {
        int hk = (h >> bit) & 1;
        int ik = (i >> bit) & 1;
        int jk = (j >> bit) & 1;
        int sum = hk + ik + jk;

        if ((g >> bit) & 1) {
            if (sum == 0) {
                a |= (1 << bit);
            } else if (sum == 3) {
                a |= (1 << bit);
                b |= (1 << bit);
                c |= (1 << bit);
            } else {
                cout << -1 << nl;
                return;
            }
        } else {
            if (sum == 0) continue;
            if (sum == 1) {
                if (hk == 1) {
                    a |= (1 << bit);
                    b |= (1 << bit);
                } else if (ik == 1) {
                    b |= (1 << bit);
                    c |= (1 << bit);
                } else {
                    c |= (1 << bit);
                    a |= (1 << bit);
                }
            } else {
                cout << -1 << nl;
                return;
            }
        }
    }
    cout << a << " " << b << " " << c << nl;
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
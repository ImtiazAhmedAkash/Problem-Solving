/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// NXS2 - Bitwise Operators

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

    if ((n & (n - 1)) == 0) {
        cout << -1 << nl;
        return;
    }

    int a = 0, b = 0;
    for (int bit = 0; bit <= 30; bit++) {
        if (n & (1 << bit)) {
            if (a == 0) {
                a |= (1 << bit);
            } else {
                b |= (1 << bit);
            }
        }
    }
    cout << a << " " << b << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Non-coprime Split

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
    int l, r;
    cin >> l >> r;
    if (l != 2 && l % 2 == 0) {
        cout << l / 2 << " " << l / 2 << nl;
    } else if (r != 2 && r % 2 == 0) {
        cout << r / 2 << " " << r / 2 << nl;
    } else if (l != r && r > 4) {
        cout << (r - 1) / 2 << " " << (r - 1) / 2 << nl;
    } else {
        for (int i = 2; i * i <= l; i++) {
            if (l % i == 0 && gcd(i, l - i) != 1) {
                cout << i << " " << l - i << nl;
                return;
            }
        }
        cout << -1 << nl;
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
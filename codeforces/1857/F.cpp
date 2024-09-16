/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sum and Product

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
    map<int, int> M;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        M[x]++;
    }

    int q;
    cin >> q;
    while (q--) {
        ll x, y;
        cin >> x >> y;

        // discriminant of a quadratic equation (a_i)^2 - x(a_i) + y = 0;
        ll disc = x * x - 4 * y;

        if (disc < 0) {
            cout << 0 << " ";
            continue;
        }

        ll sq = sqrtl(disc) + 2;
        while (sq * sq > disc) sq--;

        if (sq * sq != disc || (x + sq) % 2) {
            cout << 0 << " ";
            continue;
        }

        ll x1 = (x + sq) / 2;
        ll x2 = x - x1;

        if (x1 * x2 != y) {
            cout << 0 << " ";
            continue;
        }

        ll ans = 0;
        if (x1 == x2) {
            ans = 1LL * M[x1] * (M[x1] - 1) / 2;
        } else {
            ans = 1LL * M[x1] * M[x2];
        }
        cout << ans << " ";
    }
    cout << nl;
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
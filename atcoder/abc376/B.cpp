/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Hands on Ring (Easy)

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
    int n, q;
    cin >> n >> q;

    auto calculate = [&](int src, int dest, int obs) -> int {
        if (src > dest) swap(src, dest);
        int ans = 0;
        if (src < obs && obs < dest) {
            ans = n - dest + src;
        } else {
            ans = dest - src;
        }
        return ans;
    };

    int L = 1, R = 2;
    int ans = 0;
    while (q--) {
        char c;
        int tar;
        cin >> c >> tar;

        if (c == 'L') {
            ans += calculate(L, tar, R);
            L = tar;
        } else {
            ans += calculate(R, tar, L);
            R = tar;
        }
    }

    cout << ans << nl;
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
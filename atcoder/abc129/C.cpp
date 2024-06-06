/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Typical Stairs

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1000000007;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> steps(n + 1, -1);
    vector<bool> bad(n + 1, false);
    while (m--) {
        int x;
        cin >> x;
        bad[x] = true;
    }

    auto fun = [&](auto self, int x) -> int {
        if (x < 0 || bad[x]) return 0;
        if (x == 0) return 1;
        if (steps[x] != -1) return steps[x];
        return steps[x] = (self(self, x - 1) + self(self, x - 2)) % mod;
    };

    cout << fun(fun, n) << nl;
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
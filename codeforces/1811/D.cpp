/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Umka and a Long Flight

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 50;

vector<ll> F(N + 5);
void precalculate() {
    F[0] = F[1] = 1;
    for (int i = 2; i <= N; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    auto fun = [&](auto&& self, int n, int x, int y) -> bool {
        if (n == 1) return true;
        if (F[n] < y) {
            return self(self, n - 1, y - F[n], x);
        }
        if (y + F[n] <= F[n + 1]) {
            return self(self, n - 1, y, x);
        }
        return false;
    };

    cout << (fun(fun, n, x, y) ? "YES" : "NO") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precalculate();

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
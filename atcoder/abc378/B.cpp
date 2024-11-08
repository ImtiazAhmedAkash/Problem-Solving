/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Garbage Collection

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
    vector<int> Rm(n + 1), K(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> K[i] >> Rm[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int x, d;
        cin >> x >> d;

        auto check = [&](ll mid) -> bool {
            return Rm[x] + mid * K[x] >= d;
        };

        ll L = 0, R = inf;
        while (L < R) {
            ll M = L + (R - L) / 2;
            if (check(M)) {
                R = M;
            } else {
                L = M + 1;
            }
        }

        cout << Rm[x] + L * K[x] << nl;
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
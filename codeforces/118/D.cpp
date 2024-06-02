/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Caesar's Legions

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 100000000;
const int N = 2e5 + 5;

void solve() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    vector dp(n1 + 1, vector(n2 + 1, vector(k1 + 1, vector<int>(k2 + 1, -1))));

    auto fun = [&](auto&& self, int rem_f, int rem_h, int sf, int sh) -> int {
        if (rem_f < 0 || rem_h < 0 || k1 < sf || k2 < sh) return 0;
        if (rem_f == 0 && rem_h == 0) return 1;

        auto& ans = dp[rem_f][rem_h][sf][sh];
        if (ans != -1) return ans;

        int foot = self(self, rem_f - 1, rem_h, sf + 1, 0);
        int horse = self(self, rem_f, rem_h - 1, 0, sh + 1);

        return ans = (0LL + foot + horse) % mod;
    };

    cout << fun(fun, n1, n2, 0, 0) << nl;
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
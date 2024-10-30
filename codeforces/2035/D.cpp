/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Yet Another Real Number Problem

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    auto addMod = [&](ll x, ll y) -> ll {
        ll ans = x + y;
        if (ans >= mod) ans -= mod;
        return ans;
    };

    auto subMod = [&](ll x, ll y) -> ll {
        ll ans = x - y;
        if (ans < 0) ans += mod;
        return ans;
    };

    ll ans = 0;
    stack<pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
        int cur = A[i];
        int cnt = 0;
        while (cur % 2 == 0) {
            cur /= 2;
            cnt++;
        }

        while (!stk.empty()) {
            auto [x, y] = stk.top();
            if (cnt >= 30 || x <= cur * (1LL << cnt)) {
                stk.pop();
                ans = subMod(ans, 1LL * x * power(2, y) % mod);
                ans = addMod(ans, x);
                cnt += y;
            } else {
                break;
            }
        }

        stk.push({cur, cnt});
        ans = addMod(ans, 1LL * cur * power(2, cnt) % mod);
        cout << ans << " \n"[i + 1 == n];
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Integer Cards

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
    int n, m;
    cin >> n >> m;
    map<int, int> M;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        M[x]++;
        ans += x;
    }
    while (m--) {
        int b, c;
        cin >> b >> c;
        queue<pair<int, int>> Q;
        queue<int> R;
        for (auto [x, y] : M) {
            if (b == 0 || c <= x) break;
            int cur = min(b, y);
            b -= cur;
            M[x] -= cur;
            if (M[x] == 0) R.push(x);
            Q.push({c, cur});
            ans += 1LL * cur * (c - x);
        }
        while (!R.empty()) {
            M.erase(R.front());
            R.pop();
        }
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            M[x] += y;
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
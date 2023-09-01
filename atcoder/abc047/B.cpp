/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Snuke's Coloring 2 (ABC Edit)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int w, h, n;
    cin >> w >> h >> n;
    pair<int, int> p, q, r, s;
    p = {0, 0}, q = {w, 0}, r = {w, h}, s = {0, h};
    while (n--) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) {
            p.first = max(p.first, x);
            s.first = max(s.first, x);
        } else if (a == 2) {
            q.first = min(q.first, x);
            r.first = min(r.first, x);
        } else if (a == 3) {
            p.second = max(p.second, y);
            q.second = max(q.second, y);
        } else {
            r.second = min(r.second, y);
            s.second = min(s.second, y);
        }
    }
    int ans = max(0, q.first - p.first) * max(0, s.second - p.second);
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
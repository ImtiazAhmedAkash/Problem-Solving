/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Large Queue

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int q;
    cin >> q;
    deque<pair<ll, ll>> A;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int c, x;
            cin >> c >> x;
            A.push_back({c, x});
        }
        else {
            int k;
            cin >> k;
            ll ans = 0;
            while (k) {
                auto [c, x] = A.front();
                A.pop_front();
                if (k < c) {
                    ans += 1LL * k * x;
                    c -= k;
                    k = 0;
                    A.push_front({c, x});
                }
                else {
                    ans += 1LL * c * x;
                    k -= c;
                }
            }
            cout << ans << nl;
        }
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
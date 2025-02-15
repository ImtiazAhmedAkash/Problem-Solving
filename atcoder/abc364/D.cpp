/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - K-th Nearest

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
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    sort(A.begin(), A.end());

    auto check = [&](int mid, int x, int k) -> bool {
        int right = upper_bound(A.begin(), A.end(), x + mid) - A.begin();
        int left = lower_bound(A.begin(), A.end(), x - mid) - A.begin();
        return right - left >= k;
    };

    while (q--) {
        int x, k;
        cin >> x >> k;
        int L = 0, R = inf;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (check(M, x, k)) {
                R = M;
            } else {
                L = M + 1;
            }
        }
        cout << L << nl;
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
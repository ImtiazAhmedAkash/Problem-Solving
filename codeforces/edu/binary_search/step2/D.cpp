/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Children Holiday

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> t(n), z(n), y(n), ans(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> z[i] >> y[i];
    }

    auto check = [&](int mid) {
        ll res = 0;
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            int balloon = mid / (t[i] * z[i] + y[i]) * z[i];
            int rem = mid % (t[i] * z[i] + y[i]);
            balloon += min(z[i], rem / t[i]);
            tmp[i] = balloon;
            res += balloon;
        }
        if (res >= m) {
            ans = tmp;
            return true;
        }
        return false;
    };

    int lo = -1, hi = INF;  // hi = possible, lo = impossible
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << nl;
    int total = 0;
    for (auto i : ans) {
        if (total + i > m) i = m - total;
        total += i;
        cout << i << " ";
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
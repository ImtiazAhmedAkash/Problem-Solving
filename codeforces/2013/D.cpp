/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Minimize the Difference

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e15;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;

    auto check_min = [&](ll mid) -> bool {
        auto B = A;
        for (int i = n - 1; i > 0; i--) {
            if (B[i] < mid) {
                B[i - 1] -= (mid - B[i]);
            }
        }
        return B.front() >= mid;
    };

    ll L = -INF, R = INF;
    while (L < R) {
        ll M = L + (R - L + 1) / 2;
        if (check_min(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    ll mini = R;

    auto check_max = [&](ll mid) -> bool {
        auto B = A;
        for (int i = 0; i + 1 < n; i++) {
            if (B[i] > mid) {
                B[i + 1] += (B[i] - mid);
            }
        }
        return B.back() <= mid;
    };

    L = -INF, R = INF;
    while (L < R) {
        ll M = L + (R - L) / 2;
        if (check_max(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }
    ll maxi = L;

    cout << maxi - mini << nl;
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
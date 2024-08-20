/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Perform Operations to Maximize Score

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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[i].second;
    }
    sort(A.begin(), A.end());

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = A[i].first;
        int med = (i <= n / 2 ? A[(n + 2) / 2].first : A[n / 2].first);
        if (A[i].second) {
            x += k;
        }
        ans = max(ans, (ll)x + med);
    }

    auto check = [&](ll mid) -> bool {
        int have = k;
        int cnt = 0;
        for (int i = n - 1; i > 0; i--) {
            if (A[i].first >= mid) {
                cnt++;
            } else if (mid - A[i].first <= have && A[i].second) {
                cnt++;
                have -= (mid - A[i].first);
            }
        }
        return cnt >= (n + 1) / 2;
    };

    ll L = 0, R = 1e9;
    while (L < R) {
        ll M = L + (R - L + 1) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    ans = max(ans, A[n].first + R);
    cout << ans << nl;
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
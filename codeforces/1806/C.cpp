/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sequence Master

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
    ll ans = 0;
    vector<ll> A(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> A[i];
        ans += abs(A[i]);
    }

    sort(A.begin() + 1, A.end());

    if (n == 1) {
        ans = min(ans, abs(A[1] - A[2]));
    }
    if (n == 2) {
        ll cur = 0;
        for (int i = 1; i <= 2 * n; i++) {
            cur += abs(A[i] - 2);
        }
        ans = min(ans, cur);
    }
    if (n % 2 == 0) {
        vector<int> good(2 * n + 1, -1);
        good.back() = n;
        ll cur = 0;
        for (int i = 1; i <= 2 * n; i++) {
            cur += abs(A[i] - good[i]);
        }
        ans = min(ans, cur);
    }

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
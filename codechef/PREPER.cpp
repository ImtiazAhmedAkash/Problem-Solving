/*  In the Name of ALLAH, the most gracious, the most merciful  */

// PREPER - Perfect Prefixes

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<ll> pref(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + A[i];
        if (pref[i] == 1LL * i * (i + 1) / 2) {
            ans++;
        }
    }

    vector<int> B(n + 1);
    for (int i = 1; i + 1 <= n; i++) {
        int before = (1LL * i * (i + 1) / 2 == pref[i]);
        int after = (1LL * i * (i + 1) / 2 == pref[i] - A[i] + A[i + 1]);
        B[i] = after - before;
    }

    int odd = 0, even = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            odd = max(0, odd + B[i]);
        } else {
            even = max(0, even + B[i]);
        }
        cur = max({cur, odd, even});
    }

    cout << ans + cur << nl;
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
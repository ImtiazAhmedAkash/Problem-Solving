/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Summation Game

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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + A[i];
    }
    ll ans = -INF;
    for (int i = n; i >= n - k; i--) {
        ll bob = pref[i] - pref[max(0, i - x)];
        ll rem = pref[max(0, i - x)];
        ans = max(ans, rem - bob);
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
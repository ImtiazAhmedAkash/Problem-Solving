/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Alice's Adventures in Cutting Cake

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
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    ll sum = 0;
    vector<int> P(n + 1);
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        if (sum >= v) {
            cnt++;
            sum = 0;
            P[cnt] = i;
        }
    }

    if (cnt < m) {
        cout << -1 << nl;
        return;
    }

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + A[i];
    }

    cnt = 0;
    sum = 0;
    vector<int> S(n + 1);
    for (int i = n; i > 0; i--) {
        sum += A[i];
        if (sum >= v) {
            cnt++;
            sum = 0;
            S[cnt] = i;
        }
    }

    ll ans = pref[n] - pref[P[m]];
    for (int i = 1; i <= m; i++) {
        int r = S[i] - 1;
        int l = P[m - i];
        ans = max(ans, pref[r] - pref[l]);
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
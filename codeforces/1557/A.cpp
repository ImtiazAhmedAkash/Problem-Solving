/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Ezzat and Two Subsequences

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
    ll suff = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        suff += A[i];
    }

    sort(A.begin() + 1, A.end());

    double ans = -INF;
    ll pref = 0;
    for (int i = 1; i < n; i++) {
        pref += A[i];
        suff -= A[i];
        double cur = (pref * 1.0 / i) + (suff * 1.0 / (n - i));
        ans = max(ans, cur);
    }

    cout << fixed << setprecision(10);
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ±1 Operation 2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e6;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + A[i];
    }

    while (q--) {
        int x;
        cin >> x;
        int indx = prev(upper_bound(A.begin(), A.end(), x)) - A.begin();
        ll ans = 1LL * x * indx - pref[indx];
        ans += pref[n] - pref[indx] - 1LL * (n - indx) * x;
        cout << ans << nl;
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
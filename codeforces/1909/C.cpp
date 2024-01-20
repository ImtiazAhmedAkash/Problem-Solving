/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Heavy Intervals

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
    vector<ll> l(n), r(n), w(n);
    for (auto &x : l) cin >> x;
    for (auto &x : r) cin >> x;
    for (auto &x : w) cin >> x;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (r[i] - l[i]) * w[i];
    }
    sort(l.begin(), l.end());
    set<ll> st;
    for (int i = 0; i < n; i++) {
        st.insert(r[i]);
    }
    vector<ll> diff(n);
    for (int i = n - 1; ~i; i--) {
        r[i] = *st.lower_bound(l[i]);
        st.erase(r[i]);
        diff[i] = r[i] - l[i];
    }
    sort(diff.begin(), diff.end());
    sort(w.begin(), w.end(), greater());
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += diff[i] * w[i];
    }
    ans = min(ans, cur);
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
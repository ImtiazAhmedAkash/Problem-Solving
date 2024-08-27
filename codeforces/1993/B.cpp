/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Parity and Sum

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
    vector<ll> even;
    ll odd = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x & 1) {
            odd = max(odd, x);
        } else {
            even.push_back(x);
        }
    }

    if (even.size() == 0 || even.size() == n) {
        cout << 0 << nl;
        return;
    }

    sort(even.begin(), even.end());
    auto check = [&]() -> int {
        int ans = 0;
        ll mx = odd;
        for (auto x : even) {
            if (x < mx) {
                mx += x;
                ans++;
            } else {
                mx += 2LL * x;
                ans += 2;
            }
        }
        return ans;
    };

    int ans = check();
    reverse(even.begin(), even.end());
    ans = min(ans, check());
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
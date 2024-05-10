/*  In the Name of ALLAH, the most gracious, the most merciful  */

// POWPM - Powered Parameters

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
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
            ans += n;
            continue;
        }
        ll x = A[i];
        for (int j = 0; j < n && x <= inf; j++) {
            if (x <= A[j]) ans++;
            x *= A[i];
        }
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
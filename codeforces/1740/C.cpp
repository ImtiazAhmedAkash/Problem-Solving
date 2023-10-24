/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bricks and Bags

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
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    ll ans = 0;
    for (int i = 2; i < n; i++) {
        ans = max(ans, abs(A[i] - A.front()) + abs(A[i] - A[i - 1]));
    }
    for (int i = n - 3; i >= 0; i--) {
        ans = max(ans, abs(A[i] - A.back()) + abs(A[i] - A[i + 1]));
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
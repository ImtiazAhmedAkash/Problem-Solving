/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Ferris Wheel

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
    int n, x;
    cin >> n >> x;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    int ans = 0;
    for (int l = 0, r = n - 1; l <= r;) {
        if (l == r || x < A[l] + A[r]) {
            r--;
        } else {
            l++, r--;
        }
        ans++;
    }
    cout << ans << nl;
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
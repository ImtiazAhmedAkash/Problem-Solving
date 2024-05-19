/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sigma Problem

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e8;
const int N = 1e5;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> A(n);
    for (auto& x : A) {
        cin >> x;
        ans += 1LL * x * (n - 1);
    }

    sort(A.begin(), A.end());
    for (int l = 0, r = n - 1; l < n; l++) {
        r = max(l + 1, r);
        r = min(n - 1, r);
        while (l < r && A[l] + A[r] >= mod) {
            r--;
        }
        ans -= 1LL * mod * (n - 1 - r);
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
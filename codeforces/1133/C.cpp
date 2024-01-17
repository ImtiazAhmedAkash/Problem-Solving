/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Balanced Team

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
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        while (l <= r && A[r] - A[l] > 5) {
            l++;
        }
        ans = max(ans, r - l + 1);
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
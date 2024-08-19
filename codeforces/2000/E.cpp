/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Photoshoot for Gorillas

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
    int r, c, k;
    cin >> r >> c >> k;
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater());

    vector<ll> B;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int x1 = max(1, j - k + 1);
            int x2 = min(j, c - k + 1);
            int x = x2 - x1 + 1;

            int y1 = max(1, i - k + 1);
            int y2 = min(i, r - k + 1);
            int y = y2 - y1 + 1;

            B.push_back(1LL * x * y);
        }
    }
    sort(B.begin(), B.end(), greater());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * A[i] * B[i];
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
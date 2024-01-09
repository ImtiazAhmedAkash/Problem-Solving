/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Number of Equal

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
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    ll ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        int x = 1;
        while (i + 1 < n && A[i] == A[i + 1]) {
            i++, x++;
        }
        int y = 0;
        while (j < m && B[j] <= A[i]) {
            if (A[i] == B[j]) y++;
            j++;
        }
        ans += 1LL * x * y;
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
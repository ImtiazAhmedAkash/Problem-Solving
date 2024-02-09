/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Katana Thrower

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
    int n, h;
    cin >> n >> h;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }
    int mx_A = *max_element(A.begin(), A.end());
    sort(B.begin(), B.end(), greater());

    ll ans = 0;
    int i = 0;
    while (i < n && mx_A < B[i] && h) {
        h -= min(h, B[i]);
        ans++, i++;
    }
    ans += (h + mx_A - 1) / mx_A;
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
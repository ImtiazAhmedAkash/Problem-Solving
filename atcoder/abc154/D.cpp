/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dice in Line

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1000;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    vector<double> P(N + 1);
    for (int i = 1; i <= N; i++) {
        int sum = i * (i + 1) / 2;
        P[i] = (double)sum / i;
    }

    double ans = 0, cur = 0;
    for (int l = 0, r = 0; r < n; r++) {
        cur += P[A[r]];
        if (r - l + 1 < k) continue;
        ans = max(ans, cur);
        cur -= P[A[l]];
        l++;
    }
    cout << fixed << setprecision(10) << ans << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Walk and Teleport

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 1e9 + 7;
const int N = 1e7 + 5;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += min((A[i] - A[i - 1]) * a, b);
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
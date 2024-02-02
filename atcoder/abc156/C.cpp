/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rally

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    int ans = inf;
    for (int p = 0; p <= 100; p++) {
        int cur = 0;
        for (auto x : A) {
            cur += (x - p) * (x - p);
        }
        ans = min(ans, cur);
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Shopping (Easy Version)

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
    for (auto& x : A) cin >> x;
    int ans = 0;
    int d = 2 * 3 * 5 * 7;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll cost = 1;
        for (int bit = 0; bit < n; bit++) {
            if ((mask & (1 << bit))) {
                cost *= A[bit];
            }
        }
        if (cost % d == 0) ans++;
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
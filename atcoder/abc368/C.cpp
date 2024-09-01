/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Triple Attack

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

    ll ans = 0;
    for (auto &x : A) {
        int h = x;
        ans += 3 * (h / 5);
        h %= 5;
        while (h > 0) {
            ans++;
            if (ans % 3 == 0) {
                h -= 3;
            } else {
                h--;
            }
        }
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
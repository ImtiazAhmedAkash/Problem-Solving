/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Two Vessels

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b) swap(a, b);
    int ans = 0;
    while (a > b) {
        a -= c;
        b += c;
        ans++;
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
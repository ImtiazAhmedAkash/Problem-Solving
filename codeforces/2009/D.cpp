/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Satyam and Counting

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
    map<int, int> y_zero, y_one;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y == 0) {
            y_zero[x]++;
        } else {
            y_one[x]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (y_zero.count(i) && y_one.count(i)) {
            ans += n - 2;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (y_zero.count(i) && y_one.count(i - 1) && y_one.count(i + 1)) {
            ans++;
        }
        if (y_one.count(i) && y_zero.count(i - 1) && y_zero.count(i + 1)) {
            ans++;
        }
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
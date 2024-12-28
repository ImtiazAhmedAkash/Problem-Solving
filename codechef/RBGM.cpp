/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// RBGM - Red-Blue Sort

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
    int same = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == i) {
            same++;
        }
    }

    int ans = 0;
    if (same == n) {
        ans = n;
    } else if (same) {
        ans = n - 1;
    } else {
        ans = n - 2;
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
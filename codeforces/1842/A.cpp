/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tenzing and Tsondu

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * If Tenzing's monsters has more abilities in total than that of Tsondu's, Tenzing will win.
 * If both have same, the answer is draw. Otherwise, Tsondu will win.
 */

void solve() {
    int n, m;
    cin >> n >> m;
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum1 += x;
    }
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        sum2 += x;
    }
    string ans;
    if (sum1 == sum2) ans = "Draw";
    else if (sum1 > sum2) ans = "Tsondu";
    else ans = "Tenzing";

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Make It Round

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const ll inf = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll two = 0, five = 0, tmp = n;
    while (tmp % 2 == 0) {
        two++;
        tmp /= 2;
    }
    while (tmp % 5 == 0) {
        five++;
        tmp /= 5;
    }
    ll ans = n, op = 1;
    while (two < five && op * 2 <= m) {
        ans *= 2;
        op *= 2;
        two++;
    }
    while (two > five && op * 5 <= m) {
        ans *= 5;
        op *= 5;
        five++;
    }
    while (op * 10 <= m) {
        ans *= 10;
        op *= 10;
    }
    ans = ans * (m / op);
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
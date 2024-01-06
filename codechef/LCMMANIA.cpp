/*  In the Name of ALLAH, the most gracious, the most merciful  */

// LCMMANIA - LCM Mania

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
    if (__builtin_popcount(n) == 1) {
        cout << -1 << nl;
        return;
    }
    int x = 1, tmp = n;
    while (tmp % 2 == 0) {
        x *= 2;
        tmp /= 2;
    }
    cout << x << " " << x << " " << (n - x) / 2 << nl;
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
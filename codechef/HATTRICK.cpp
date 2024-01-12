/*  In the Name of ALLAH, the most gracious, the most merciful  */

// HATTRICK - Hattrick

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
    vector<char> A(6);
    for (auto &x : A) cin >> x;
    int mx = 0, cur = 0;
    for (auto x : A) {
        if (x == 'W') {
            cur++;
            mx = max(mx, cur);
        } else {
            cur = 0;
        }
    }
    cout << (mx >= 3 ? "YES" : "NO") << nl;
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
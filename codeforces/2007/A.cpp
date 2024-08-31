/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dora's Set

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
    int l, r;
    cin >> l >> r;
    vector<int> even, odd;
    for (int i = l; i <= r; i++) {
        if (i & 1) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
    }

    int ans = 0;
    while (odd.size() >= 2 && even.size() >= 1) {
        ans++;
        odd.pop_back();
        odd.pop_back();
        even.pop_back();
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
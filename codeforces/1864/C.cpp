/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Divisor Chain

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    ans.push_back(1);
    while ((ans.back() * 2) <= n) {
        ans.push_back(ans.back() * 2);
    }
    n -= ans.back();
    while (n) {
        int msb = __lg(n);
        ans.push_back(ans.back() + (1 << msb));
        n -= (1 << msb);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for (auto x : ans) cout << x << " ";
    cout << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Unhappy Hacking (ABC Edit)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    string s;
    cin >> s;
    string ans = "";
    for (auto x : s) {
        if (x == 'B') {
            if (!ans.empty()) ans.pop_back();
        } else {
            ans += x;
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
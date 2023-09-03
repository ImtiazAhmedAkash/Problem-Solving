/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Two Binary Strings

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    string ans = "NO";
    for (int i = 0; i + 1 < n; i++) {
        if (a.substr(i, 2) == "01" && b.substr(i, 2) == "01") ans = "YES";
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
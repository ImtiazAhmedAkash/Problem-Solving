/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Count ABC Again

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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ".." + s + "..";

    int ans = 0;
    for (int i = 2; i <= n + 1; i++) {
        if (s.substr(i, 3) == "ABC") {
            ans++;
        }
    }

    auto check = [&](int i) -> int {
        if (s[i] == 'A') {
            return (s.substr(i, 3) == "ABC");
        } else if (s[i] == 'B') {
            return (s.substr(i - 1, 3) == "ABC");
        } else {
            return (s.substr(i - 2, 3) == "ABC");
        }
    };

    while (q--) {
        int x;
        char c;
        cin >> x >> c;
        x++;
        int before = check(x);
        if (before && s[x] != c) {
            ans--;
        }
        char prev = s[x];
        s[x] = c;
        int after = check(x);
        if (after && s[x] != prev) {
            ans++;
        }
        cout << ans << nl;
    }
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
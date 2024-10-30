/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Action Figures

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
    string s;
    cin >> s;
    s = '-' + s;

    set<int> zero, one;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            zero.insert(i);
        } else {
            one.insert(i);
        }
    }

    ll ans = 1LL * n * (n + 1) / 2;
    while (!one.empty()) {
        int x = *one.rbegin();
        ans -= x;
        one.erase(x);

        while (!zero.empty() && *zero.rbegin() > x) {
            zero.erase(--zero.end());
        }

        if (!zero.empty()) {
            zero.erase(--zero.end());
        } else if (!one.empty()) {
            one.erase(one.begin());
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
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
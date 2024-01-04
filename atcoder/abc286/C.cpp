/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rotate and Palindrome

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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    auto fun = [&](string t) -> ll {
        int diff = 0;
        for (int i = 0; i < n / 2; i++) {
            diff += (t[i] != t[n - i - 1]);
        }
        return 1LL * diff * b;
    };

    ll ans = fun(s);
    for (int i = 1; i < n; i++) {
        s.push_back(s.front());
        s.erase(s.begin());
        ans = min(ans, 1LL * a * i + fun(s));
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
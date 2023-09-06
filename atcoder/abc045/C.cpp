/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Many Formulas

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF =(1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    for (int mask = 0; mask < (1 << (n - 1)); mask++) {
        string t = "";
        for (int i = 0; i < n; i++) {
            t += s[i];
            if ((mask & (1 << i)) || i + 1 == n) {
                ans += stoll(t);
                t = "";
            }
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
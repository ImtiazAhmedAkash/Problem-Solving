/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Channel

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    string ans = "NO";
    if (n == a) {
        ans = "YES";
    } else {
        int cur = a;
        for (auto x : s) {
            if (x == '+') cur++;
            if (cur == n) ans = "MAYBE";
        }
        cur = a;
        for (auto x : s) {
            if (x == '+') cur++;
            else cur--;
            if (cur == n) ans = "YES";
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
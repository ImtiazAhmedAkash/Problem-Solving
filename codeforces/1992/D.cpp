/*  In the Name of ALLAH, the most gracious, the most merciful  */

// D - Test of Love

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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = 'L' + s;
    
    int total = 0;
    for (int i = 0; i <= n; ) {
        int log = -1, water = -1;
        if (s[i] == 'L') {
            for (int j = i + 1; j <= i + m; j++) {
                if (j > n) {
                    cout << (total <= k ? "YES" : "NO") << nl;
                    return;
                }
                if (s[j] == 'L') {
                    log = j;
                } else if (s[j] == 'W') {
                    water = j;
                }
            }
            if (log != -1) {
                i = log;
            } else if (water != -1) {
                i = water;
            } else {
                cout << "NO" << nl;
                return;
            }
        } else if (s[i] == 'W') {
            total++;
            i++;
        } else {
            cout << "NO" << nl;
            return;
        }
    }
    cout << (total <= k ? "YES" : "NO") << nl;
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
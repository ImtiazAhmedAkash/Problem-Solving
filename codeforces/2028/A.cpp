/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Alice's Adventures in "Chess"

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

    int x = 0, y = 0;
    for (int j = 0; j < 100; j++) {
        for (int i = 0; i < n; i++) {
            if (s[i] == 'N') y++;
            if (s[i] == 'S') y--;
            if (s[i] == 'E') x++;
            if (s[i] == 'W') x--;

            if (x == a && y == b) {
                cout << "YES" << nl;
                return;
            }
        }
    }

    cout << "NO" << nl;
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
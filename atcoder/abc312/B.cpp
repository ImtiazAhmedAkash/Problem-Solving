/*  In the Name of ALLAH, the most gracious, the most merciful  */

// TaK Code

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i + 8 < n; i++) {
        for (int j = 0; j + 8 < m; j++) {
            bool ok = true;
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    if (s[i + x][j + y] != s[8 + i - x][8 + j - y]) ok = false;
                    else {
                        if ((x == 3 || y == 3) && s[i + x][j + y] != '.') ok = false;
                        else if (x < 3 && y < 3 && s[i + x][j + y] != '#') ok = false;
                    }
                }
            }
            if (ok) {
                cout << i + 1 << " " << j + 1 << nl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
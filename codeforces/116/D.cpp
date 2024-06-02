/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Lawnmower

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
    int n, m;
    cin >> n >> m;
    vector A(n, vector<char>(m));
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            tot += (A[i][j] == 'W');
        }
    }

    int x = 0, y = 0;
    int dir = 1;
    int ans = 0;

    while (tot) {
        // same row
        int last = -1, cnt = 0;
        if (dir == 1) {
            for (int j = y + 1; j < m; j++) {
                if (A[x][j] == 'W') last = j, cnt++;
            }
        } else {
            for (int j = y - 1; j >= 0; j--) {
                if (A[x][j] == 'W') last = j, cnt++;
            }
        }
        if (last != -1) {
            ans += abs(last - y);
            tot -= cnt, y = last;
            continue;
        }

        // next row
        if (dir == 1) {
            for (int j = y; x + 1 < n && j < m; j++) {
                if (A[x + 1][j] == 'W') last = j;
            }
        } else {
            for (int j = y; x + 1 < n && j >= 0; j--) {
                if (A[x + 1][j] == 'W') last = j;
            }
        }
        if (last != -1) {
            ans += 1 + abs(last - y);
            x++, y = last, tot--;
            dir *= -1;
            continue;
        }

        x++, ans++;
        dir *= -1;
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
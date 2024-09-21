/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// The Very Beautiful Blanket

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 200;

vector ans(N + 5, vector<int>(N + 5));

void precalculate() {
    for (int i = 1; i <= N; i += 2) {
        int cur = 512 * (i / 2);
        for (int j = 1; j <= N; j += 2) {
            ans[i][j] = cur;
            ans[i][j + 1] = cur + 1;
            ans[i + 1][j] = cur + 2;
            ans[i + 1][j + 1] = cur + 3;
            cur += 4;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << n * m << nl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j] << " \n"[j == m];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precalculate();

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
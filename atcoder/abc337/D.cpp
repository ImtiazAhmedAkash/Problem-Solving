/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cheating Gomoku Narabe

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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> A(h);
    for (auto &x : A) cin >> x;
    int ans = inf;
    for (int i = 0; i < h; i++) {
        int cnt = 0, dot = 0;
        for (int l = 0, r = 0; r < w; r++) {
            if (A[i][r] == 'x') {
                l = r + 1;
                cnt = 0, dot = 0;
                continue;
            }
            cnt++;
            if (A[i][r] == '.') dot++;
            while (l <= r && k <= cnt) {
                ans = min(ans, dot);
                if (A[i][l] == '.') dot--;
                l++, cnt--;
            }
        }
    }

    for (int j = 0; j < w; j++) {
        int cnt = 0, dot = 0;
        for (int l = 0, r = 0; r < h; r++) {
            if (A[r][j] == 'x') {
                l = r + 1;
                cnt = 0, dot = 0;
                continue;
            }
            cnt++;
            if (A[r][j] == '.') dot++;
            while (l <= r && k <= cnt) {
                ans = min(ans, dot);
                if (A[l][j] == '.') dot--;
                l++, cnt--;
            }
        }
    }

    cout << (ans == inf ? -1 : ans) << nl;
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
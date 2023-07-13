/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Let's Get a Perfect Score

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    string str[n];
    for (int i = 0; i < n; i++) cin >> str[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (str[i][j] == 'o' || str[k][j] == 'o') cnt++;
            }
            if (cnt == m) ans++;
        }
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
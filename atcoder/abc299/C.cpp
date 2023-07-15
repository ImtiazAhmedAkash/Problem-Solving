/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dango

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 2005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (s.find('-') == string::npos || s.find('o') == string::npos) {
        cout << -1 << nl;
        return;
    }

    int ans = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'o') cnt++;
        if (i == n - 1 || s[i] == '-') {
            ans = max(cnt, ans);
            cnt = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'o') cnt++;
        if (i == 0 || s[i] == '-') {
            ans = max(cnt, ans);
            cnt = 0;
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
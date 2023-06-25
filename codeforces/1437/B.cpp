/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Reverse Binary Strings

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Find out the total number of consecutive pairs for '0' and '1' individually.
 * The maximum between them is the answer.
 */

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s += '2';
    int ans = 0;

    bool ok = false;
    int cnt = 0, tmp = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == '1') {
            ok = true;
            cnt++;
        } 
        else if (ok && s[i] != '1') {
            tmp += cnt - 1;
            cnt = 0;
            ok = false;
        }
    }
    ans = max(ans, tmp);

    ok = false;
    cnt = 0, tmp = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == '0') {
            ok = true;
            cnt++;
        } else if (ok && s[i] != '0') {
            tmp += cnt - 1;
            cnt = 0;
            ok = false;
        }
    }
    ans = max(ans, tmp);

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
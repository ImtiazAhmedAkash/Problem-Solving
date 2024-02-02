/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ADVITIYA4 - Another Good String

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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && s[i] == s[j]) j++;
        ans = max(ans, j - i);
        i = j - 1;
    }
    int lst = 0;
    for (int i = n - 1; ~i && s[i] == s.back(); i--) {
        lst++;
    }
    cout << ans << " ";
    while (q--) {
        char c;
        cin >> c;
        if (c == s.back()) {
            lst++;
        } else {
            lst = 1;
        }
        s += c;
        ans = max(ans, lst);
        cout << ans << " ";
    }
    cout << nl;
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
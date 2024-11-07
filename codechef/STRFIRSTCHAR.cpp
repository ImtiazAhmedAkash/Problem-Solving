/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// STRFIRSTCHAR - Replace With First

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
    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << 0 << nl;
    } else if (s.front() != t.front()) {
        cout << -1 << nl;
    } else {
        if (n < m) {
            swap(n, m);
            swap(s, t);
        }
        int pref = 0;
        for (int i = 0; i < m; i++) {
            if (s[i] != t[i]) break;
            pref++;
        }
        int suff = 0;
        for (int i = 1; i < m; i++) {
            if (s[n - i] != t[m - i]) break;
            suff++;
        }

        cout << (suff + pref >= m ? 1 : 2) << nl;
    }
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
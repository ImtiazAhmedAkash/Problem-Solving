/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Operate 1

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
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;

    if (abs((int)s.size() - (int)t.size()) > 1) {
        cout << "No" << nl;
        return;
    }

    if (s.size() == t.size()) {
        int diff = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                diff++;
            }
        }
        cout << (diff <= 1 ? "Yes" : "No") << nl;
        return;
    }

    if (s.size() > t.size()) {
        swap(s, t);
    }

    int n = s.size();
    int m = t.size();
    for (int i = 0, j = 0; i < m; i++) {
        if (t[i] == s[j]) {
            j++;
            if (j == n) {
                cout << "Yes" << nl;
                return;
            }
        }
    }

    cout << "No" << nl;
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
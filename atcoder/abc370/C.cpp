/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Word Ladder

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
    string s, t;
    cin >> s >> t;

    vector<string> ans;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] > t[i]) {
            s[i] = t[i];
            ans.push_back(s);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] < t[i]) {
            s[i] = t[i];
            ans.push_back(s);
        }
    }

    cout << ans.size() << nl;
    for (auto &x : ans) {
        cout << x << nl;
    }
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
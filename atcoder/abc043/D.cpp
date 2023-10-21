/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Unbalanced

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
    string s;
    cin >> s;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            cout << i + 1 << " " << i + 2 << nl;
            return;
        }
    }
    for (int i = 0; i + 2 < s.size(); i++) {
        if (s[i] == s[i + 2]) {
            cout << i + 1 << " " << i + 3 << nl;
            return;
        }
    }
    cout << "-1 -1" << nl;
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
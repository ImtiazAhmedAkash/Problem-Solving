/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Airport Code

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
    int indx = 0;
    int n = s.size();
    for (int i = 0; i < n && indx < 3; i++) {
        if (s[i] == tolower(t[indx])) {
            indx++;
        }
    }
    cout << (indx == 3 || indx == 2 && t.back() == 'X' ? "Yes" : "No") << nl;
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
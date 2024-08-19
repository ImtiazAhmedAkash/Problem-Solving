/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Primary Task

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
    if (s.size() <= 2 || s.substr(0, 2) != "10") {
        cout << "NO" << nl;
        return;
    }
    string t = s.substr(2);
    cout << ((t.front() == '0' || t == "1") ? "NO" : "YES") << nl;
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
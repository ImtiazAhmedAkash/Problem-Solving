/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Take ABC

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
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        t.push_back(s[i]);
        int n = t.size();
        if (n >= 3 && t.substr(n - 3) == "ABC") {
            for (int j = 0; j < 3; j++) t.pop_back();
        }
    }
    cout << t << nl;
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
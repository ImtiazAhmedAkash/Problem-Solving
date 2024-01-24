/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Hidden Secret!

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
    string a, b;
    getline(cin, a);
    getline(cin, b);
    string s = "";
    for (auto c : a) {
        if (isalpha(c)) {
            s += tolower(c);
        }
    }
    sort(s.begin(), s.end());
    string t = "";
    for (auto c : b) {
        if (isalpha(c)) {
            t += tolower(c);
        }
    }
    sort(t.begin(), t.end());
    cout << (s == t ? "Yes" : "No") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    cin.ignore();
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Not a Substring

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    string s;
    cin >> s;
    string ans1 = "", ans2 = "";
    for (int i = 0; i < s.size(); i++) {
        ans1 += "()";
    }
    for (int i = 0; i < s.size(); i++) {
        ans2 += '(';
    }
    for (int i = 0; i < s.size(); i++) {
        ans2 += ')';
    }

    if (ans1.find(s) == string::npos) {
        cout << "YES" << nl << ans1 << nl;
    } else if (ans2.find(s) == string::npos) {
        cout << "YES" << nl << ans2 << nl;
    } else {
        cout << "NO" << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Reverse String

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string s, t;
    cin >> s >> t;
    string rev_s = s, ans = "NO";
    reverse(rev_s.begin(), rev_s.end());
    if (s.find(t) != string::npos || rev_s.find(t) != string::npos) {
        ans = "YES";
    } else {
        string tmp;
        for (int i = 1; !s.empty(); i++) {
            tmp = s + rev_s.substr(i);
            if (tmp.find(t) != string::npos) {
                ans = "YES";
                break;
            }
            s.pop_back();
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
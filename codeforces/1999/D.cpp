/*  In the Name of ALLAH, the most gracious, the most merciful  */

// D - Slavic's Exam

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
    
    bool ok = false;
    for (int i = 0, j = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            if (j < t.size()) {
                s[i] = t[j++];
            } else {
                s[i] = 'a';
            }
        } else if (j < t.size() && s[i] == t[j]) {
            j++;
        }
        if (j == t.size()) {
            ok = true;
        }
    }
    
    if (ok) {
        cout << "YES" << nl << s << nl;
    } else {
        cout << "NO" << nl;
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
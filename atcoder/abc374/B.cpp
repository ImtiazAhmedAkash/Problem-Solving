/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Unvarnished Report

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
    
    if (s == t) {
        cout << 0 << nl;
        return;
    }
    
    if (s.size() < t.size()) {
        swap(s, t);
    }
    while (s.size() > t.size()) {
        t += '.';
    }
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            cout << i + 1 << nl;
            return;
        }
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
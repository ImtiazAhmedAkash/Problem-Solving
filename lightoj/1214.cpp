/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Large Division

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
    int n;
    cin >> s >> n;
    n = abs(n);
    ll rem = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') continue;
        rem = rem * 10 + (s[i] - '0');
        rem %= n;
    }
    cout << (rem == 0 ? "divisible" : "not divisible") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    
    return 0;
}
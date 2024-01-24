/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Substring Frequency

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
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    queue<char> t;
    for (auto c : b) {
        t.push(c);
    }
    queue<char> s;
    for (int i = 0; i < min(m, n); i++) {
        s.push(a[i]);
    }
    int ans = (s == t ? 1 : 0);
    for (int i = min(m, n); i < n; i++) {
        s.pop();
        s.push(a[i]);
        if (s == t) ans++;
    }
    cout << ans << nl;
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
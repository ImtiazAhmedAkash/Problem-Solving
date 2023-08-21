/*  In the Name of ALLAH, the most gracious, the most merciful  */

// First ABC

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool a, b, c;
    a = b = c = false;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') a = true;
        else if (s[i] == 'B') b = true;
        else c = true;
        ans++;
        if (a && b && c) break;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}
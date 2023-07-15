/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Chess 960

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string s;
    cin >> s;
    
    bool ok = false;
    int x = 0, parity = 0;
    string ans = "No";
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            parity ^= (i % 2);
        }
        if (s[i] == 'R') ok = !ok;
        if (s[i] == 'K' && ok) x = 1;
    }
    
    if (x && parity) ans = "Yes";
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
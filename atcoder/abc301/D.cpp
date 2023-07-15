/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bitmask

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1LL << 62)
#define mod 998244353
#define N 75
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string s;
    ll n;
    cin >> s >> n;
    
    ll ans = 0, x = s.size() - 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '?') ans += ((1LL << (x - i)) * (s[i] - '0'));
    }
    
    if (ans > n) {
        cout << -1 << nl;
        return;
    }
    
    for (int i = 0; i < s.size(); i++) {
        ll tmp = 0;
        if (s[i] == '?') tmp = ((1LL << (x - i)));
        if (tmp + ans <= n) ans += tmp;
    }
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
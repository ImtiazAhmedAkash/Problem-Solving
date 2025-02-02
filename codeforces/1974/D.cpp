/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Ingenuity-2

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    string ans;
    int north = 0, south = 0, east = 1, west = 1;
    for (auto &c : s) {
        if (c == 'E') {
            ans += (east == 0 ? 'R' : 'H');
            east ^= 1;
        }
        if (c == 'W') {
            ans += (west == 0 ? 'R' : 'H');
            west ^= 1;
        }
        if (c == 'N') {
            ans += (north == 0 ? 'R' : 'H');
            north ^= 1;
        }
        if (c == 'S') {
            ans += (south == 0 ? 'R' : 'H');
            south ^= 1;
        }
    }
    
    if (ans.find('R') == -1 || ans.find('H') == -1) {
        cout << "NO" << nl;
        return;
    }
    
    int hx = 0, hy = 0, rx = 0, ry = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] == 'R') {
            if (s[i] == 'E') rx++;
            if (s[i] == 'W') rx--;
            if (s[i] == 'N') ry++;
            if (s[i] == 'S') ry--;
        }
        else { // 'H'
            if (s[i] == 'E') hx++;
            if (s[i] == 'W') hx--;
            if (s[i] == 'N') hy++;
            if (s[i] == 'S') hy--;
        }
    }
    
    if (hx == rx && hy == ry) {
        cout << ans << nl;
    }
    else {
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
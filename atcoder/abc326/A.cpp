/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 2UP3DOWN

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
    int x, y;
    cin >> x >> y;
    string ans = "No";
    if (x - 3 <= y && x + 2 >= y) ans = "Yes";
    cout << ans << nl; 
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Minimize Abs 1

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
    int n, l, r;
    cin >> n >> l >> r;
    while (n--) {
        int x;
        cin >> x;
        int ans = x;
        if (x <= l) ans = l;
        else if (x >= r) ans = r;
        cout << ans << " ";
    }
    cout << nl;
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
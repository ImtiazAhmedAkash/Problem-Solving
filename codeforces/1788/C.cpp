/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Matching Numbers

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
    cin >> n;
    if ((n & 1) == 0) {
        cout << "No" << nl;
        return;
    }
    cout << "Yes" << nl;
    for (int i = 1, val = 2 * n; i <= n; i++) {
        cout << i << " " << val << nl;
        val -= 2;
        if (val < n) {
            val = (2 * n) - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
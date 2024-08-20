/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Generate Permutation

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
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << nl;
        return;
    }
    for (int i = n; i > 0; i -= 2) {
        cout << i << " ";
    }
    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }
    cout << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Superultra's Favorite Permutation

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
    if (n <= 4) {
        cout << -1 << nl;
        return;
    }

    for (int i = 1; i <= n; i += 2) {
        if (i != 5) {
            cout << i << " ";
        }
    }

    cout << "5 4 ";

    for (int i = 2; i <= n; i += 2) {
        if (i != 4) {
            cout << i << " ";
        }
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
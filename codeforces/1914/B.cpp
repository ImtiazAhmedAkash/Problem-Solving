/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Preparing for the Contest

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 3e5;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = n - k; i; i--) {
        cout << i << " ";
    }
    for (int i = n - k + 1; i <= n; i++) {
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
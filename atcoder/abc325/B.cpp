/*  In the Name of ALLAH, the most gracious, the most merciful  */

// World Meeting

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 24;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> E(n), T(n);
    for (int i = 0; i < n; i++) {
        cin >> E[i] >> T[i];
    }
    int ans = 0;
    for (int i = 0; i < 24; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            int x = (T[j] + i) % mod;
            if (x >= 9 && x < 18) cur += E[j];
        }
        ans = max(ans, cur);
    }
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
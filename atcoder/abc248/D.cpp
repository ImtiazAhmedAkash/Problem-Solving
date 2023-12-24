/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Range Count Query

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
    map<int, vector<int>> M;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        M[x].push_back(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        int ans = 0;
        if (M.find(x) != M.end()) {
            int L = lower_bound(M[x].begin(), M[x].end(), l) - M[x].begin();
            int R = upper_bound(M[x].begin(), M[x].end(), r) - M[x].begin();
            ans = R - L;
        }
        cout << ans << nl;
    }
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
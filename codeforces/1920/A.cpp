/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Satisfying Constraints

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
    set<int> A;
    int L = 0, R = inf;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            L = max(L, y);
        } else if (x == 2) {
            R = min(R, y);
        } else {
            A.insert(y);
        }
    }
    int ans = R - L + 1;
    for (auto x : A) {
        if (L <= x && x <= R) ans--;
    }
    cout << max(0, ans) << nl;
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
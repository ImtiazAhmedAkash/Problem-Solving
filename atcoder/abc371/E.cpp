/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// I Hate Sigma Problems

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
    vector<int> A(n + 1);
    map<int, vector<int>> M;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        M[A[i]].push_back(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = n - i + 1;
        ans += 1LL * x * (x + 1) / 2;
    }

    for (auto [x, y] : M) {
        if (y.size() >= 2) {
            for (int i = 0, j = 1; j < y.size(); i++, j++) {
                int l = y[i];
                int r = y[j];
                ll bad = 1LL * l * (n - r + 1);
                ans -= bad;
            }
        }
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
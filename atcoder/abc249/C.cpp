/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Just K

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
    int n, k;
    cin >> n >> k;
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        map<char, int> M;
        for (int bit = 0; bit < n; bit++) {
            if (mask & (1 << bit)) {
                for (auto x : A[bit]) {
                    M[x]++;
                }
            }
        }
        int cur = 0;
        for (auto [x, y] : M) {
            if (y == k) cur++;
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
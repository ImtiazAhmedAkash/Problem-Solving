/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vertical Writing

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
    vector<string> A(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        mx = max(mx, (int)A[i].size());
    }
    for (int i = 0; i < n; i++) {
        while (A[i].size() < mx) {
            A[i] += '*';
        }
    }
    for (int j = 0; j < mx; j++) {
        string ans;
        for (int i = n - 1; i >= 0; i--) {
            ans += A[i][j];
        }
        while (!ans.empty() && ans.back() == '*') {
            ans.pop_back();
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
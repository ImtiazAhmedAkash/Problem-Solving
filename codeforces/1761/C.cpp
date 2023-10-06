/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Set Construction

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
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<set<int>> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i].insert(i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '1') {
                ans[j + 1].insert(i + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i].size() << " ";
        for (auto x : ans[i]) cout << x << " ";
        cout << nl;
    }
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
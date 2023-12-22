/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Set Meal

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
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> md(n + 1);
    vector<pair<int, int>> A(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> md[i];
    }
    for (int i = 1; i <= m; i++) {
        int sd;
        cin >> sd;
        A[i] = {sd, i};
    }
    sort(A.begin(), A.end());
    vector<int> max_val(n + 1, A.back().first), indx(n + 1, m);
    vector<set<int>> st(n + 1);

    while (l--) {
        int c, d;
        cin >> c >> d;
        st[c].insert(d);
        while (st[c].find(A[indx[c]].second) != st[c].end()) {
            indx[c]--;
            max_val[c] = A[indx[c]].first;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, md[i] + max_val[i]);
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
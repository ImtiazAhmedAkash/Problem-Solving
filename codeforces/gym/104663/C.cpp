/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Don't Let Them Pass

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
    int n, m;
    cin >> n >> m;
    vector<int> A(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x == 1) A[j] = i;
        }
    }
    
    vector C(n, vector(m, -1));
    function<int(int, int)> fun = [&] (int j, int i) -> int {
        if (i < 0 || i >= n) return inf;
        if (j == m) return 0;
        if (C[i][j] != -1) return C[i][j];
        return C[i][j] = abs(A[j] - i) + min({fun(j + 1, i - 1), fun(j + 1, i), fun(j + 1, i + 1)});
    };
    
    int ans = inf;
    for (int i = 0; i < n; i++) {
        int cur = fun(0, i);
        ans = min(ans, cur);
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
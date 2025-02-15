/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Doubles

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<map<int, int>> A(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
        for (int j = 0; j < cnt[i]; j++) {
            int x;
            cin >> x;
            A[i][x]++;
        }
    }
    
    auto calculate = [&](int x, int y) -> double {
        if (A[x].size() > A[y].size()) swap(x, y);
        double cur = 0;
        for (auto &[a, b] : A[x]) {
            if (A[y].find(a) == A[y].end()) continue;
            int c = A[y][a];
            cur += ((1.0 * b) / cnt[x]) * ((1.0 * c) / cnt[y]);
        }
        return cur;
    };
    
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans = max(ans, calculate(i, j));
        }
    }
    
    cout << fixed << setprecision(15);
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
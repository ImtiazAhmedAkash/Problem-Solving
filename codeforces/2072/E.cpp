/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Do You Love Your Hero and His Two-Hit Multi-Target Attacks?

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
const int N = 1e5 + 5;

vector<int> A;
void precalculate() {
    for (int i = 0; i * (i - 1) / 2 <= N; i++) {
        A.push_back(i * (i - 1) / 2);
    }
}

void solve() {
    int n;
    cin >> n;
    int cur = 1;
    vector<pair<int, int>> ans;
    while (n) {
        int x = (upper_bound(A.begin(), A.end(), n)) - A.begin();
        x--;
        for (int i = cur; i < cur + x; i++) {
            ans.push_back({cur, i});
        }
        n -= A[x];
        cur += 500;
    }
    
    cout << ans.size() << nl;
    for (auto &[a, b] : ans) {
        cout << a << " " << b << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precalculate();
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}
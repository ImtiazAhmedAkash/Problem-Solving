/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Team Training

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
const int mod = 1e9 + 7;
const int N = 100;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    sort(A.begin(), A.end(), greater<>());
    
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        if (A[i] * cnt >= x) {
            ans++;
            cnt = 0;
        }
    }
    
    cout << ans << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Going to the Cinema

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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    
    int ans = 0;
    int cnt = 0;
    if (mp.count(0) && mp[0] == 1 && !mp.count(1)) {
        ans += 1;
        mp.erase(0);
        cnt = 1;
    } 
    else if (!mp.count(0)) { // no one would go
        ans += 1;
    }
    
    vector<pair<int, int>> A;
    for (auto &[x, y] : mp) {
        A.push_back({x, y});
    }
    A.push_back({inf, 0});
    
    for (int i = 0; i + 1 < A.size(); i++) {
        cnt += A[i].second;
        if (cnt > A[i].first && cnt < A[i + 1].first) ans++;
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
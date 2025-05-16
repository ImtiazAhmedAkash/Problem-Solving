/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// F - Distinct of Distincts

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
    int n, m;
    cin >> n >> m;
    vector ans(n, vector<int>(m));
    if (n >= m) {
        for (int j = 0, maxi = n; j < m; j++, maxi--) {
            int cur = 1;
            for (int i = 0; i < n; i++) {
                ans[i][j] = min(cur, maxi);
                cur++;
            }
        }
    }
    else {
        for (int i = 0, maxi = m; i < n; i++, maxi--) {
            int cur = 1;
            for (int j = 0; j < m; j++) {
                ans[i][j] = min(cur, maxi);
                cur++;
            }
        }
    }
    
    set<int> st;
    for (int i = 0; i < n; i++) {
        map<int, int> mp;
        for (int j = 0; j < m; j++) {
            mp[ans[i][j]]++;
        }
        st.insert(mp.size());
    }
    for (int j = 0; j < m; j++) {
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[ans[i][j]]++;
        }
        st.insert(mp.size());
    }
    
    cout << st.size() << nl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j + 1 == m];
        }
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
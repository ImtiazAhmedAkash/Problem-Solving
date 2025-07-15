/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Giant Domino

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    set<int> st;
    for (int i = 1; i < n - 1; i++) {
        st.insert(A[i]);
    }
    
    int cur = A.front();
    int target = A.back();
    int ans = 2;
    while (!st.empty() && cur * 2 < target) {
        auto it = st.upper_bound(2 * cur);
        if (it == st.begin()) break;
        it--;
        cur = *it;
        st.erase(it);
        ans++;
    }
    
    cout << (cur * 2 < target ? -1 : ans) << nl;
    
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
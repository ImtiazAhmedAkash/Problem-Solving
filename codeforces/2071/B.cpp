/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Perfecto

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
    
    auto is_square = [&](ll x) -> bool {
        ll sq = sqrt(x) + 5;
        while (sq * sq > x) sq--;
        return sq * sq == x;
    };
    
    if (is_square(1LL * n * (n + 1) / 2)) {
        cout << -1 << nl;
        return;
    }
    
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    
    vector<int> ans(n);
    ans[0] = 2;
    st.erase(2);
    ll sum = 2;
    for (int i = 1; i < n; i++) {
        int taken = -1;
        for (auto &x : st) {
            if (!is_square(sum + x)) {
                taken = x;
                break;
            }
        }
        ans[i] = taken;
        sum += taken;
        st.erase(taken);
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
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
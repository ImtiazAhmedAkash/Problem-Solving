/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// 	D - Conflict 2

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
    int n, q;
    cin >> n >> q;
    vector<int> op(q + 1), pc(q + 1);
    vector<string> S(q + 1, "");
    for (int i = 1; i <= q; i++) {
        cin >> op[i] >> pc[i];
        if (op[i] == 2) {
            string t;
            cin >> t;
            reverse(t.begin(), t.end());
            S[i] = t;
        }
    }
    
    string ans;
    int cur = 0;
    for (int i = q; i > 0; i--) {
        if (op[i] == 1 && cur == pc[i]) {
            cur = 0;
        }
        else if (op[i] == 2 && cur == pc[i]) {
            ans += S[i];
        }
        else if (op[i] == 3 && cur == 0) {
            cur = pc[i];
        }
    }
    
    reverse(ans.begin(), ans.end());
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
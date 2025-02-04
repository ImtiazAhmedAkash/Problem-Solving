/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Outstanding Impressionist

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
    map<int, int> Fixed;
    set<int> Available;
    for (int i = 1; i <= 2 * n; i++) {
        Available.insert(i);
    }
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        A[i] = {l, r};
        if (l == r) {
            Fixed[l]++;
            Available.erase(l);
        }
    }
    
    string ans;
    for (auto &[l, r] : A) {
        if (l == r) {
            ans += (Fixed[l] == 1 ? '1' : '0');
        }
        else {
            auto it = Available.lower_bound(l);
            if (it != Available.end() && *it <= r) {
                ans += '1';
            }
            else {
                ans += '0';
            }
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
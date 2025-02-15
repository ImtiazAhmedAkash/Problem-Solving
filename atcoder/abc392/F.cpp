/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// F - Insert

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> queries(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> queries[i];
    }
    
    ordered_set<int> os;
    for (int i = 0; i < n; i++) {
        os.insert(i);
    }
    
    vector<int> ans(n);
    for (int i = n; i > 0; i--) {
        auto it = os.find_by_order(queries[i] - 1);
        ans[*it] = i;
        os.erase(it);
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
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
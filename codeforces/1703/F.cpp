/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Yet Another Problem About Pairs Satisfying an Inequality

#include <bits/stdc++.h>
using namespace std;

// Ordered Set
/*
 * greater<T> -> Descending order
 * less<T> -> Ascending order
 * s.find_by_order(k - 1);  // k-th biggest/smallest element in set
 * s.order_of_key(x);    // how many elements in set are less than x
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    ordered_set<pair<int, int>> os;
    for (int i = n; i > 0; i--) {
        if (A[i] < i) {
            int sz = os.size();
            int small = os.order_of_key({i + 1, A[i]});
            ans += sz - small;
            os.insert({A[i], i});
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Salary Queries

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

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
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    ordered_set<pair<int, int>> os;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        os.insert({A[i], i});
    }
    
    while (q--) {
        char op;
        cin >> op;
        if (op == '!') {
            int k, x;
            cin >> k >> x;
            os.erase({A[k], k});
            A[k] = x;
            os.insert({A[k], k});
        }
        else {
            int a, b;
            cin >> a >> b;
            int r = os.order_of_key({b + 1, 0});
            int l = os.order_of_key({a, 0});
            cout << r - l << nl;
        }
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
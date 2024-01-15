/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sliding Window Median

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
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
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> Q;
    ordered_set<pair<int, int>> OS;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Q.push({x, i});
        OS.insert({x, i});
        if ((int)OS.size() == k) {
            auto it = OS.find_by_order((k - 1) / 2);
            cout << (*it).first << " ";
            OS.erase(Q.front());
            Q.pop();
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Greetings

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
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (auto& [x, y] : A) {
        cin >> x >> y;
    }
    sort(A.begin(), A.end(), greater());

    ordered_set<int> os;
    ll ans = 0;
    for (auto& [x, y] : A) {
        ans += os.order_of_key(y + 1);
        os.insert(y);
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
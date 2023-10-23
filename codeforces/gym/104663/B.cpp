/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Digit Occurrence Sum

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> s;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> cnt(10);

    auto Add = [&](int m) {
        string t = to_string(m);
        for (auto x : t) {
            cnt[x - '0']++;
        }
    };

    auto Delete = [&](int m) {
        string t = to_string(m);
        for (auto x : t) {
            cnt[x - '0']--;
        }
    };

    while (n--) {
        int m;
        cin >> m;
        Add(m);
        s.insert(m);
    }

    while (q--) {
        char c;
        int m;
        cin >> c >> m;
        if (c == '+') {
            if (s.find(m) == s.end()) {
                Add(m);
                s.insert(m);
            } else {
                Delete(m);
                s.erase(m);
            }
        } else if (c == '-') {
            if (s.size() >= m) {
                m = *(s.find_by_order(m - 1));
                Delete(m);
                s.erase(m);
            }
        } else {
            if (s.find(m) == s.end()) {
                cout << -1 << nl;
                continue;
            }
            int ans = 0;
            string t = to_string(m);
            for (int i = 0; i < t.size(); i++) {
                ans += cnt[t[i] - '0'];
            }
            cout << ans << nl;
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
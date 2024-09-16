/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Character Blocking

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    vector<string> s(2);
    cin >> s[0] >> s[1];
    int n = s[0].size();
    int t, q;
    cin >> t >> q;

    set<int> bad;
    for (int i = 0; i < n; i++) {
        if (s[0][i] != s[1][i]) {
            bad.insert(i);
        }
    }

    int cur_t = 1;
    queue<pair<int, int>> blocked;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            x--;
            bad.erase(x);
            blocked.push({cur_t + t, x});

        } else if (op == 2) {
            int a, x, b, y;
            cin >> a >> x >> b >> y;
            --a, --x, --b, --y;
            bad.erase(x);
            bad.erase(y);
            swap(s[a][x], s[b][y]);
            if (s[a][x] != s[!a][x]) {
                bad.insert(x);
            }
            if (s[b][y] != s[!b][y]) {
                bad.insert(y);
            }

        } else {
            cout << (bad.empty() ? "YES" : "NO") << nl;
        }

        cur_t++;
        while (!blocked.empty() && blocked.front().first <= cur_t) {
            auto [x, y] = blocked.front();
            blocked.pop();
            if (s[0][y] != s[1][y]) {
                bad.insert(y);
            }
        }
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
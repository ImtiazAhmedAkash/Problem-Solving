/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Nearest Excluded Points

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

// U -> R -> D -> L direction
vector<int> dx = {-1, +0, +1, +0};
vector<int> dy = {+0, +1, +0, -1};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    map<pair<int, int>, bool> mp;
    for (auto &[x, y] : A) {
        cin >> x >> y;
        mp[{x, y}] = true;
    }

    map<pair<int, int>, pair<int, int>> ans;
    queue<pair<int, int>> q;
    for (auto &[x, y] : A) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (mp.find({nx, ny}) == mp.end()) {
                ans[{x, y}] = {nx, ny};
                q.push({x, y});
                break;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (mp.find({nx, ny}) != mp.end() && ans.find({nx, ny}) == ans.end()) {
                ans[{nx, ny}] = ans[{x, y}];
                q.push({nx, ny});
            }
        }
    }

    for (auto &[x, y] : A) {
        auto p = ans[{x, y}];
        cout << p.first << " " << p.second << nl;
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
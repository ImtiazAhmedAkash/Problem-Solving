/*  In the Name of ALLAH, the most gracious, the most merciful  */

// King's Path

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;
vector<int> dir = {0, +1, -1, 0, -1, -1, +1, +1, 0};

void solve() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    map<pair<int, int>, int> M;
    int n;
    cin >> n;
    while (n--) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int i = a; i <= b; i++) {
            M[{r, i}] = -1;
        }
    }

    auto bfs = [&](int sx, int sy) {
        M[{sx, sy}] = 0;
        queue<pair<int, int>> Q;
        Q.push({sx, sy});
        while (!Q.empty()) {
            auto [ax, ay] = Q.front();
            Q.pop();
            for (int i = 0; i + 1 < dir.size(); i++) {
                int nx = ax + dir[i];
                int ny = ay + dir[i + 1];
                if (M.find({nx, ny}) == M.end()) continue;
                if (M[{nx, ny}] == -1) {
                    M[{nx, ny}] = M[{ax, ay}] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    };

    bfs(sx, sy);
    cout << (M.find({tx, ty}) == M.end() ? -1 : M[{tx, ty}]) << nl;
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
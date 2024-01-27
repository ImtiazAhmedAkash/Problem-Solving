/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Qualifying Contest

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
    int n, m;
    cin >> n >> m;
    vector G(m + 1, vector<pair<int, string>>());
    while (n--) {
        string s;
        int reg, score;
        cin >> s >> reg >> score;
        G[reg].push_back({score, s});
    }
    for (int i = 1; i <= m; i++) {
        sort(G[i].begin(), G[i].end(), greater());
        if (G[i].size() > 2 && G[i][1].first == G[i][2].first) {
            cout << "?" << nl;
        } else {
            cout << G[i][0].second << " " << G[i][1].second << nl;
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
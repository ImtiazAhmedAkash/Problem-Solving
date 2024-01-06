/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Loong Tracking

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
    int n, q;
    cin >> n >> q;
    deque<pair<int, int>> D;
    for (int i = 1; i <= n; i++) {
        D.push_back({i, 0});
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            char c;
            cin >> c;
            D.pop_back();
            auto [x, y] = D.front();
            if (c == 'R') x++;
            else if (c == 'L') x--;
            else if (c == 'U') y++;
            else if (c == 'D') y--;
            D.push_front({x, y});
        } else {
            int x;
            cin >> x;
            x--;
            cout << D[x].first << " " << D[x].second << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Humidifier 2

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
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> A(n);
    for (auto &x : A) cin >> x;
    
    vector<pair<int, int>> floors;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '.') {
                floors.push_back({i, j});
            }
        }
    }
    
    auto calculate = [&](int x, int y) -> int {
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == '.' && (abs(floors[x].first - i) + abs(floors[x].second - j) <= d || abs(floors[y].first - i) + abs(floors[y].second - j) <= d)) {
                    st.insert({i, j});
                }
            }
        }
        return (int)st.size();
    };
    
    int ans = 0;
    for (int i = 0; i < floors.size(); i++) {
        for (int j = i + 1; j < floors.size(); j++) {
            ans = max(ans, calculate(i, j));
        }
    }
    
    cout << ans << nl;
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
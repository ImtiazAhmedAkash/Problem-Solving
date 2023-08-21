/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Roulette

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> bet[n];
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            bet[i].push_back(x);
        }
    }
    int val;
    cin >> val;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bet[i].size(); j++) {
            if (bet[i][j] == val) {
                a.push_back({(int) bet[i].size(), i});
                break;
            }
        }
    }
    if (a.empty()) {
        cout << 0 << nl;
    } else {
        vector<int> ans;
        sort(a.begin(), a.end());
        int mini = a.front().first;
        for (auto [x, y] : a) {
            if (x == mini) ans.push_back(y + 1);
        }
        cout << ans.size() << nl;
        for (auto x : ans) cout << x << " ";
        cout << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}
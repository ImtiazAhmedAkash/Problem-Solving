/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Farmer John's Card Game

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
    vector<int> card(n * m + 5);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            card[x] = i;
        }
    }
    
    vector<int> ans;
    vector<int> used(n + 1, false);
    for (int i = 0; i < n; i++) {
        int cow = card[i];
        if (used[cow]) {
            cout << -1 << nl;
            return;
        }
        ans.push_back(cow);
        used[cow] = true;
    }
    
    int cur = n, indx = 0;
    while (cur < n * m) {
        if (ans[indx] != card[cur]) {
            cout << -1 << nl;
            return;
        }
        cur++;
        indx++;
        indx %= n;
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
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
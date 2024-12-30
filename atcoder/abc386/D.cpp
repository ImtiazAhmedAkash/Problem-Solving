/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Diagonal Separation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> minW, maxB;
    set<int> row;
    for (int i = 0; i < m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        
        if (row.find(x) == row.end()) {
            row.insert(x);
            maxB[x] = 0;
            minW[x] = inf;
        }
        
        if (c == 'W') {
            minW[x] = min(minW[x], y);
        } else {
            maxB[x] = max(maxB[x], y);
        }
    }
    
    int mx_col = 0;
    while (!row.empty()) {
        int cur = *row.rbegin();
        row.erase(cur);
        mx_col = max(mx_col, maxB[cur]);
        if (minW[cur] <= mx_col) {
            cout << "No" << nl;
            return;
        } 
    }
    
    cout << "Yes" << nl;
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
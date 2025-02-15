/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// C - Paint to make a rectangle

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
    int h, w;
    cin >> h >> w;
    vector<string> A(h);
    for (auto &x : A) cin >> x;
    
    set<int> row, col;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (A[i][j] == '#') {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    
    int minCol = *col.begin();
    int maxCol = *col.rbegin();
    int minRow = *row.begin();
    int maxRow = *row.rbegin();
    
    for (int i = minRow; i <= maxRow; i++) {
        for (int j = minCol; j <= maxCol; j++) {
            if (A[i][j] == '.') {
                cout << "No" << nl;
                return;
            }
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
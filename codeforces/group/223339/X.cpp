/*  In the Name of ALLAH, the most gracious, the most merciful  */

// The maximum path-sum

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

int fun(int row, int col, int& n, int& m, vector<vector<int>>& A) {
    if (row == n || col == m) return -inf;
    if (row + 1 == n && col + 1 == m) return A[row][col];
    return A[row][col] + max(fun(row + 1, col, n, m, A), fun(row, col + 1, n, m, A));
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    
    cout << fun(0, 0, n, m, A) << nl;
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
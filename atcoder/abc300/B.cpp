/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Same Map in the RPG World

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Two grids will be given and two operations can be performed.
 * In a vertical shifting, each row can be replaced by its next row, 
 * and the last row will be replaced by the first.
 * In a horizontal shifting, each column can be replaced by its next column, 
 * and the last column will be replaced by the first.
 * 
 * The task is to find out if the given grids can be the same after performing these two operations multiple times.
 * 
 * Lets say, n = total number of rows, and m = total number of columns
 * The first observation is, the vertical shifting can be performed at most (n - 1) times.
 * Because the grid will be the same after performing vertical shifting, 0 times and n times.
 * 
 * Similarly, the horizontal shifting can be performed at most (m - 1) times.
 * Because, the grid will be the same after performing horizontal shifting, 0 times and m times.
 * 
 * So, check for all the combinations of vertical shifting and horizontal shifting.
 * It can be done in O(n * m) complexity.
 * 
 * If we perform the vertical shifting v times and horizontal shifting h times in grid A[n][m],
 * Then the character of A[i][j] will be A[(i + v) % n][(j + h) % m].
 * 
 * In each combinations, fixed a grid, and check if the other grid becomes similar at some time.
 * If it becomes similar, then the answer will be "Yes".
 * If after checking all the combinations, the two grids don't match, the answer will be "No".
 */

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int v = 0; v < n; v++) {
        for (int h = 0; h < m; h++) {
            bool ok = true;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] != b[(i + v) % n][(j + h) % m]) ok = false;
                }
            }

            if (ok) {
                cout << "Yes" << nl;
                return;
            }
        }
    }
    cout << "No" << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
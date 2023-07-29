/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Anti Sudoku

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

// The easiest approach is to "replace all '2' with '1'" and the grid will be anti-sudoku.

void solve() {
    vector<pair<int, int>> v = {{0, 0}, {1, 3}, {2, 6}, {3, 1}, {4, 4}, {5, 7}, {6, 2}, {7, 5}, {8, 8}};
    vector<string> a(9);
    for (int i = 0; i < 9; i++) cin >> a[i];
    int indx = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (v[indx] == make_pair(i, j)) {
                int x = a[i][j] - '0';
                x = (x % 9) + 1;
                a[i][j] = x + '0';
                indx++;
            }
            cout << a[i][j];
        }
        cout << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// New Year and Domino

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

// A is 0-indexed, rest are 1-indexed
// C[i][j] = 1, if a domino can be placed column wise i.e. from A[i][j] to A[i + 1][j]
// R[i][j] = 1, if a domino can be placed row wise i.e. from A[i][j] to A[i][j + 1]
// col[i][j] -> total number of dominos that can be placed column wise from [1][1] to [i][j]
// row[i][j] -> total number of dominos that can be placed row wise from [1][1] to [i][j]

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> A(h);
    for (int i = 0; i < h; i++) {
        cin >> A[i];
    }
    vector C(h + 1, vector(w + 1, 0LL)), R(h + 1, vector(w + 1, 0LL));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (A[i][j] == '#') continue;
            if (i + 1 < h && A[i][j] == A[i + 1][j]) C[i + 1][j + 1] = 1;
            if (j + 1 < w && A[i][j] == A[i][j + 1]) R[i + 1][j + 1] = 1;
        }
    }
    
    vector row(h + 1, vector(w + 1, 0LL)), col(h + 1, vector(w + 1, 0LL));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            col[i][j] = C[i - 1][j] + col[i - 1][j] + col[i][j - 1] - col[i - 1][j - 1];
            row[i][j] = R[i][j - 1] + row[i - 1][j] + row[i][j - 1] - row[i - 1][j - 1];
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int row_wise = row[c][d] - row[c][b] - row[a - 1][d] + row[a - 1][b];
        int col_wise = col[c][d] - col[c][b - 1] - col[a][d] + col[a][b - 1];
        cout << (row_wise + col_wise) << nl;
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
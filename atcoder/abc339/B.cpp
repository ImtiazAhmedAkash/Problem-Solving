/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Langton's Takahashi

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
    int h, w, n;
    cin >> h >> w >> n;
    vector<string> A(h);
    for (int i = 0; i < h; i++) {
        A[i] = string(w, '.');
    }
    vector<int> dx = {-1, +0, +1, +0};
    vector<int> dy = {+0, +1, +0, -1};
    int indx = 0;

    int x = 0, y = 0;
    while (n--) {
        if (A[x][y] == '.') {
            A[x][y] = '#';
            indx = (indx + 1) % 4;
        } else {
            A[x][y] = '.';
            indx = ((indx - 1) + 4) % 4;
        }
        x = (x + dx[indx] + h) % h;
        y = (y + dy[indx] + w) % w;
    }
    for (int i = 0; i < h; i++) {
        cout << A[i] << nl;
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
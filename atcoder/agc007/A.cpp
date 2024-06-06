/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Shik and Stone

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e15;
const int mod = 998244353;
const int N = 1e6;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> A(h);
    for (auto& x : A) cin >> x;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bool row = false, col = false;
            for (int x = i + 1; x < h; x++) {
                if (A[x][j] == '#') row = true;
            }
            for (int x = j + 1; x < w; x++) {
                if (A[i][x] == '#') col = true;
            }
            if (row && col) {
                cout << "Impossible" << nl;
                return;
            }
        }
    }
    cout << "Possible" << nl;
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
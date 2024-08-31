/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Balls and Bag Query

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
    int q;
    cin >> q;
    map<int, int> M;
    while (q--) {
        int x, y;
        cin >> x;
        if (x == 1) {
            cin >> y;
            M[y]++;
        } else if (x == 2) {
            cin >> y;
            M[y]--;
            if (M[y] == 0) {
                M.erase(y);
            }
        } else {
            cout << M.size() << nl;
        }
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
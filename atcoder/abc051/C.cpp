/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Back and Forth

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 1e7 + 5;

void solve() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx;
    int dy = ty - sy;
    cout << string(dy, 'U');
    cout << string(dx, 'R');
    cout << string(dy, 'D');
    cout << string(dx + 1, 'L');
    cout << string(dy + 1, 'U');
    cout << string(dx + 1, 'R');
    cout << "DR";
    cout << string(dy + 1, 'D');
    cout << string(dx + 1, 'L');
    cout << "U" << nl;
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
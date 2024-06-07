/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Eat the Chip

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
    int h, w, ax, bx, ay, by;
    cin >> h >> w >> ax >> ay >> bx >> by;

    if (ax >= bx) {
        cout << "Draw" << nl;
        return;
    }

    int move = (bx - ax + 1) / 2;

    if ((bx - ax) & 1) {  // Alice has a chance to win
        if (ay == by || abs(ay - by) == 1) {
            cout << "Alice" << nl;
        } else if (ay < by) {
            cout << (w - ay <= move ? "Alice" : "Draw") << nl;
        } else {
            cout << (ay - 1 <= move ? "Alice" : "Draw") << nl;
        }
    } else {  // Bob has a chance to win
        if (ay == by) {
            cout << "Bob" << nl;
        } else if (ay < by) {
            cout << (by - 1 <= move ? "Bob" : "Draw") << nl;
        } else {
            cout << (w - by <= move ? "Bob" : "Draw") << nl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
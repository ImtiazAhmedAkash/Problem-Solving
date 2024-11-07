/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// CRCOLEZ - Crafty Coloring (Easy)

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
    int n, m, k;
    cin >> n >> m >> k;
    string t;
    cin >> t;

    k = min(n, m);
    string s;
    while (s.size() < k) {
        s += t;
    }

    int alice = 0, bob = 0, amove = 0, bmove = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == 'A') {
            alice += n + m - 1;
            alice -= 2 * amove;
            bob -= 2 * bmove;
            amove++;
        } else {
            bob += n + m - 1;
            alice -= 2 * amove;
            bob -= 2 * bmove;
            bmove++;
        }
    }

    if (alice == bob) {
        cout << "Draw" << nl;
    } else {
        cout << (alice > bob ? "Alice" : "Bob") << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Li Hua and Chess

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    cin >> x;
    return x;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int a = ask(1, 1);
    int b = ask(1, min(m, a + 1));
    int c = ask(min(n, a + 1), 1);

    int x = 0, y = 0;
    if (b == c && a == b) {
        x = y = a + 1;
    } else if (b < a) {
        x = b + 1;
        y = a + 1;
    } else {
        x = a + 1;
        y = c + 1;
    }

    cout << "! " << x << " " << y << endl;
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
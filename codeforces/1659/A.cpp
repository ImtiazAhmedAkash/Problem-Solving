/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Red Versus Blue

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
    int n, r, b;
    cin >> n >> r >> b;
    int x = r / (b + 1);
    int y = r % (b + 1);
    for (int i = 0; i < y; i++) {
        cout << string(x + 1, 'R') << 'B';
    }
    for (int i = y; i < b; i++) {
        cout << string(x, 'R') << 'B';
    }
    cout << string(x, 'R') << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Playoff

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = count(s.begin(), s.end(), '1');
    int zero = n - one;

    // for a value to win, it should be greater than at least (1 << one) - 1 values and
    // should be smaller than at least (1 << zero) - 1 values.
    for (int i = 1; i <= (1 << n); i++) {
        if ((1 << one) - 1 <= i - 1 && (1 << zero) - 1 <= (1 << n) - i) {
            cout << i << " ";
        }
    }
    cout << nl;
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
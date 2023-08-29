/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Row Major

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

// x is the smallest number than is not a divisor of n
// at least 'x' distinct value will be needed
// the answer will be the first 'x' letters added cyclically

void solve() {
    int n;
    cin >> n;
    string ans = string(n, 'a');
    int x = 1;
    while (n % x == 0) x++;
    for (int i = 0; i < n; i++) {
        ans[i] = 'a' + (i % x);
    }
    cout << ans << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Good Triples

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

// dp[x] = number of ways (take two zeroes, one non-zero + take one zero, two non-zeroes + take three non-zeroes)
// Exception: dp[0] = number of ways to take three zeroes
// dp vector can be created by simple bruteforce.

vector<int> dp = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};

void solve() {
    int n;
    cin >> n;

    ll ans = 1;
    while (n) {
        ans = ans * dp[n % 10];
        n /= 10;
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
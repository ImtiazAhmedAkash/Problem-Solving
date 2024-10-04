/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Counting Divisors

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e6;

vector<int> spf(N + 5);
void precalculate() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i; j <= N; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    ll ans = 1;
    while (n != 1) {
        int x = spf[n];
        int cnt = 0;
        while (n % x == 0) {
            cnt++;
            n /= x;
        }
        ans *= (cnt + 1);
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precalculate();

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
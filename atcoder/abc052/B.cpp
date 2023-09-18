/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Increment Decrement

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 0, ans = 0;
    for (auto x : s) {
        if (x == 'I') cur++;
        else cur--;
        ans = max(ans, cur);
    }
    cout << ans << nl;
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
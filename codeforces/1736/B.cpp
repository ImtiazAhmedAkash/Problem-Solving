/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Playing with GCD

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    string ans = "YES";
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (n > 2) {
        vector <int> b {a.front()};
        for (int i = 0; i + 1 < n; i++) {
            b.push_back(lcm(a[i], a[i + 1]));
        }
        b.push_back(a.back());
        for (int i = 0; i < n; i++) {
            if (gcd(b[i], b[i + 1]) != a[i]) ans = "NO";
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
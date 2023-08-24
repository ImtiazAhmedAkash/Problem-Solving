/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Good Arrays

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
    vector<ll> a(n);
    ll sum = 0;
    for (auto &x : a) {
        cin >> x;
        sum += x;
    }
    string ans = "YES";
    if (n == 1) ans = "NO";
    else {
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) sum -= 2;
            else sum -= 1;
            if (sum < 0) ans = "NO";
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
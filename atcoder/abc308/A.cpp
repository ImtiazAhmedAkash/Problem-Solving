/*  In the Name of ALLAH, the most gracious, the most merciful  */

// New Scheme

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    vector<int> a(8);
    for (auto &x : a) cin >> x;
    string ans = "Yes";
    if (!is_sorted(a.begin(), a.end())) ans = "No";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < 100 || a[i] > 675 || a[i] % 25) ans = "No";
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
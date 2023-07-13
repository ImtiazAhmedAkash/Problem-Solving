/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Swappable

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
      	int x;
        cin >> x;
        m[x]++;
    }
    ll ans = (ll) n * (n - 1) / 2;
    for (auto i : m) {
        ll val = i.second;
        ans -= (val * (val - 1) / 2);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
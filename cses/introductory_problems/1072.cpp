/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Two Knights

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
    for (int i = 1; i <= n; i++) {
        ll total_cell = 1LL * i * i;
        ll total_combination = total_cell * (total_cell - 1) / 2;
        ll attack_combination = 4LL * (i - 1) * (i - 2);
        cout << total_combination - attack_combination << nl;
    }
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
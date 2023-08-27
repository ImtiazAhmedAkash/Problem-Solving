/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Potions

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, h, x;
    cin >> n >> h >> x;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0, mini = INF;
    for (int i = 0; i < n; i++) {
        if (a[i] + h >= x && a[i] < mini) {
            mini = a[i];
            ans = i + 1;
        }
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
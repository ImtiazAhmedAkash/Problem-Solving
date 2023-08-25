/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Flower City Fence

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 200000;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    string ans = "NO";
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[1] <= N) {
        vector<int> b(a[1] + 2);
        for (int i = 1; i <= n; i++) {
            b[1] += 1;
            b[a[i] + 1] -= 1;
        }
        for (int i = 1; i <= a[1]; i++) {
            b[i] += b[i - 1];
        }
        b.pop_back();
        if (a == b) ans = "YES";
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
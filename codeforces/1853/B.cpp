/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Fibonaccharsis

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    if (k > 30) {
        cout << 0 << nl;
        return;
    }
    int ans = 0;
    vector<int> a(k);
    a.back() = n;
    for (int val = n / 2; val <= n; val++) {
        bool ok = true;
        a[k - 2] = val;
        for (int i = k - 3; i >= 0; i--) {
            a[i] = a[i + 2] - a[i + 1];
            if (a[i] > a[i + 1]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
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
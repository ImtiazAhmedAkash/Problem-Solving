/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Array and Operations

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
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int indx = n - (2 * k);
    int ans = 0;
    for (int i = 0; i < indx; i++) {
        ans += a[i];
    }
    for (int i = indx; i < indx + k; i++) {
        ans += (a[i] / a[i + k]);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
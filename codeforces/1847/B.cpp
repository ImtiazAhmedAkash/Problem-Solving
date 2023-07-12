/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Hamon Odyssey

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_power;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) min_power = a[i];
        else min_power &= a[i];
    }
    int ans = 1;
    if (min_power == 0) {
        ans = 0;
        a.push_back(INF);
        int cur_power = a[0];
        for (int i = 1; i <= n; i++) {
            if (cur_power == min_power) {
                ans++;
                cur_power = a[i];
            } else {
                cur_power &= a[i];
            }
        }
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
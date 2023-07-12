/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Co-growing Sequence

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
    vector<int> a(n), ans(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (int i = 1; i < n; i++) {
        int fixed = a[i - 1];
        int change = a[i];
        if ((fixed & change) == fixed) continue;
        int res = 0;
        for (int j = 0; j <= __lg(fixed); j++) {
            int fixed_jth_bit = ((fixed >> j) & 1);
            int change_jth_bit = ((change >> j) & 1);
            if (fixed_jth_bit == 1 && fixed_jth_bit != change_jth_bit) {
                res = (res | (1 << j));
            }
        }
        ans[i] = res;
        a[i] ^= res;
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << nl;
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
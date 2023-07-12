/*  In the Name of ALLAH, the most gracious, the most merciful  */

// And It's Non-Zero

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = INF;
    
    auto zero_count = [&] (int x, int mul) {
        int cycle = (x + 1) / mul;
        int ret = cycle * (mul / 2);
        int rem = (x + 1) % mul;
        ret += min(rem, mul / 2);
        return ret;
    };
    
    for (int i = 0, mul = 2; i <= __lg(r); i++, mul *= 2) {
        int tmp = zero_count(r, mul) - zero_count(l - 1, mul);
        ans = min(ans, tmp);
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
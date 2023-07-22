/*  In the Name of ALLAH, the most gracious, the most merciful  */

// The Morning Star

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
    map <ll, ll> x_axis, y_axis, pos_slope, neg_slope;
    ll ans = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        ans += x_axis[x]++;        // compus will point towards W and E
        ans += y_axis[y]++;        // compus will point towards N and S
        ans += pos_slope[x - y]++; // compus will point towards NE and SW
        ans += neg_slope[x + y]++; // compus will point towards NW and SE
        // this is how jiangly calculates n * (n - 1) / 2
    }
    
    // from n elements, n * (n - 1) / 2 pairs can be formed
    // the order does matter, i.e. (1, 2), (2, 1) are different pairs.
    // so, finally multiply the answer by 2
    cout << ans * 2 << nl;
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
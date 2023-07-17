/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vika and Price Tags

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

// If a[i] becomes 0 in k-th operation, it will be 0 again in (k + 3)-th, (k + 6)-th... operation.
// So, the observation is, find out the number of operation needed to make an a[i] = 0
// and take (number of operation % 3). 
// If this result is same for all the elements, all of them will be 0 after some operations.

// Let, OP = (number of operation) % 3, x = a[i], y = b[i], m = coefficient of x, n = coefficient of y

// Pattern: 
// OP = 0, when x = 0, x = 2y,          (m is odd, n is even)
// OP = 1, when y = 0, y = 2x, 3y = 2x  (m is even, n is odd)
// OP = 2, when x = y, 3x = y, 3x = 5y  (m is odd, n is odd)

// Let, x = 10, y = 15. Find the smallest m and n, such that mx = ny.
// m = lcm(x, y) / x and n = lcm(x, y) / y


ll lcm (ll a, ll b) {
    return (a * b) / gcd(a, b);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    set<int> st;
    string ans = "YES";
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) continue;
        if (a[i] == 0) {
            st.insert(0);
            continue;
        }
        if (b[i] == 0) {
            st.insert(1);
            continue;
        }
        if (a[i] == b[i]) {
            st.insert(2);
            continue;
        }
        ll LCM = lcm(a[i], b[i]);
        ll x = LCM / a[i];
        ll y = LCM / b[i];
        if ((x & 1) && !(y & 1)) {
            st.insert(0);
        } else if (!(x & 1) && (y & 1)) {
            st.insert(1);
        } else if ((x & 1) && (y & 1)) {
            st.insert(2);
        }
    }
    if (st.size() > 1) ans = "NO";
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
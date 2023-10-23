/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Divisible by three

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
    string s;
    cin >> s;
    s = '#' + s;
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + s[i] - '0';
    }
    ll ans = 0;
    vector<ll> M(3, 0);
    for (int i = 1; i <= n; i++) {
        ll rem = pref[i] % 3;
        if (rem == 0) ans++;
        ans += M[rem];
        M[rem]++;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Right Left Wrong

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
    vector<int> A(n + 1);
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pref[i] = pref[i - 1] + A[i];
    }

    string s;
    cin >> s;
    s = '.' + s;

    int l = 1, r = n;
    ll ans = 0;
    while (l <= r) {
        if (s[l] == 'L' && s[r] == 'R') {
            ans += pref[r] - pref[l - 1];
            l++, r--;
        } else if (s[l] == 'R') {
            l++;
        } else if (s[r] == 'L') {
            r--;
        }
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
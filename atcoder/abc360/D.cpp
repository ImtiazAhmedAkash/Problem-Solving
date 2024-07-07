/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Ghost Ants

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
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    vector<int> L, R;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        if (s[i] == '1') {
            R.push_back(y);
        } else {
            L.push_back(y);
        }
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    ll ans = 0;
    for (int i = 0; i < R.size(); i++) {
        int l = lower_bound(L.begin(), L.end(), R[i]) - L.begin();
        int r = upper_bound(L.begin(), L.end(), R[i] + 2 * x) - L.begin();
        ans += (r - l);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
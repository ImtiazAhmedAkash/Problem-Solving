/*  In the Name of ALLAH, the most gracious, the most merciful  */

// GeT AC

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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = '!' + s;
    vector<int> pref(n + 1);
    for (int i = 1; i + 1 <= n; i++) {
        if (s[i] == 'A' and s[i + 1] == 'C') {
            pref[i] = 1;
        }
        pref[i] += pref[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        r--;
        cout << pref[r] - pref[l - 1] << nl;
    }
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
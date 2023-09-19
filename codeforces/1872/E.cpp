/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Data Structures Fan

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i];
    }
    vector<int> ans(2);
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        ans[s[i] - '0'] ^= a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int l, r;
            cin >> l >> r;
            int range_xor = pref[r] ^ pref[l - 1];
            ans[0] ^= range_xor;
            ans[1] ^= range_xor;
        } else {
            int g;
            cin >> g;
            cout << ans[g] << " ";
        }
    }
    cout << nl;
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
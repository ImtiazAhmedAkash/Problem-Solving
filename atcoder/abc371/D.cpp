/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// 1D Country

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
    vector<pair<int, int>> A(n);
    for (auto &[x, y] : A) cin >> x;
    for (auto &[x, y] : A) cin >> y;

    sort(A.begin(), A.end());

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + A[i].second;
        A[i].second = i + 1;
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it = lower_bound(A.begin(), A.end(), make_pair(l, -1));

        if (it == A.end()) {
            cout << 0 << nl;
            continue;
        }

        int x = (*it).second;
        it = lower_bound(A.begin(), A.end(), make_pair(r + 1, -1));

        if (it == A.begin()) {
            cout << 0 << nl;
            continue;
        }

        it--;
        int y = (*it).second;
        cout << (x > y ? 0 : pref[y] - pref[x - 1]) << nl;
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
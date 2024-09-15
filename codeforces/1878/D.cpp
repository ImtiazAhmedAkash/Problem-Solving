/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Reverse Madness

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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = '-' + s;

    vector<int> L(m);
    for (auto &x : L) cin >> x;
    vector<int> R(m);
    for (auto &x : R) cin >> x;

    vector<int> delta(n + 5);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int indx = lower_bound(R.begin(), R.end(), x) - R.begin();
        int l = min(x, L[indx] + R[indx] - x);
        int r = max(x, L[indx] + R[indx] - x);
        if (l < r) {
            delta[l]++;
            delta[(l + r + 1) / 2]--;
        }
    }

    for (int i = 0; i < m; i++) {
        int l = L[i];
        int r = R[i];
        for (int j = l; j <= (l + r - 1) / 2; j++) {
            if (j != l) {
                delta[j] += delta[j - 1];
            }
            if (delta[j] & 1) {
                swap(s[j], s[r - j + l]);
            }
        }
    }

    s.erase(s.begin());
    cout << s << nl;
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
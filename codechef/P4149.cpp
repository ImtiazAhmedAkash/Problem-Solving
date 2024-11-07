/*  In the Name of ALLAH, the most gracious, the most merciful  */

// P4149 - Maximise Sum

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
    vector<int> pos, neg;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            neg.push_back(x);
        } else {
            pos.push_back(x);
        }
        ans += abs(x);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int m = neg.size();
    if (m & 1) {
        if (pos.empty()) {
            ans -= 2 * abs(neg.back());
        } else {
            if (pos.front() < abs(neg.back())) {
                ans -= 2 * pos.front();
            } else {
                ans -= 2 * abs(neg.back());
            }
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
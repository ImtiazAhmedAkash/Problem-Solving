/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Robin Hood in Town

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
    ll sum = 0;
    vector<int> A(n);
    for (auto &x : A) {
        cin >> x;
        sum += x;
    }

    if (n <= 2) {
        cout << -1 << nl;
        return;
    }

    sort(A.begin(), A.end(), greater());

    auto check = [&](ll mid) -> bool {
        ll cur = sum + mid;
        int bad = 0;
        for (int i = 1; i < n; i++) {
            if (2LL * A[i] * n < cur) {
                bad++;
            }
        }

        return n < 2 * bad;
    };

    ll L = 0, R = INF;
    while (L < R) {
        ll M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }
    cout << L << nl;
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
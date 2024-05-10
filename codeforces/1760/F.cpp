/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Quests

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void solve() {
    int n, d;
    ll c;
    cin >> n >> c >> d;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    sort(A.begin(), A.end(), greater());

    if ((c + A.front() - 1) / A.front() > d) {
        cout << "Impossible" << nl;
        return;
    }

    if (accumulate(A.begin(), A.begin() + min(n, d), 0LL) >= c) {
        cout << "Infinity" << nl;
        return;
    }

    auto check = [&](int mid) -> bool {
        int rem = d;
        ll money = 0;
        for (int i = 0; i < n && rem; i++) {
            int cur = min(rem, (d + mid - i) / (mid + 1));
            money += 1LL * cur * A[i];
            rem -= cur;
            if (c <= money) return true;
        }
        return false;
    };

    int L = 0, R = d;
    while (L < R) {
        int M = L + (R - L + 1) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    cout << R << nl;
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
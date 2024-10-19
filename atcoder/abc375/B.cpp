/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Traveling Takahashi Problem

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
    vector<pair<int, int>> A(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> A[i].first >> A[i].second;
    }

    auto dist = [&](pair<int, int> a, pair<int, int> b) -> double {
        ll x = a.first - b.first;
        ll y = a.second - b.second;
        return sqrtl((double)(x * x + y * y));
    };

    double ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        ans += dist(A[i - 1], A[i]);
    }

    cout << fixed << setprecision(10) << ans << nl;
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
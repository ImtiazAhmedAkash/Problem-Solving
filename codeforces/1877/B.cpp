/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Helmets in Night Light

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
    int n, p;
    cin >> n >> p;
    vector<int> A(n);
    for (auto &x : A) {
        cin >> x;
    }
    vector<pair<int, int>> B(n);
    for (int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        B[i] = {cost, A[i]};
    }
    sort(B.begin(), B.end());
    ll ans = p;
    int done = 1;
    for (int i = 0; i < n && B[i].first < p; i++) {
        ll cur = min(n - done, B[i].second);
        done += cur;
        ans += (cur * B[i].first);
    }
    ans += 1LL * (n - done) * p;
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
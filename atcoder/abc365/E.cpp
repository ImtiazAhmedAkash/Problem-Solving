/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Xor Sigma Problem

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    ll sum = accumulate(A.begin(), A.end(), 0LL);

    ll ans = 0;
    for (int bit = 0; bit <= 30; bit++) {
        vector<int> cnt(2);
        cnt[0] = 1;
        int pref = 0;
        for (int i = 0; i < n; i++) {
            int x = (A[i] >> bit) & 1;
            pref ^= x;
            ans += 1LL * cnt[1 ^ pref] * (1 << bit);
            cnt[pref]++;
        }
    }

    cout << ans - sum << nl;
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
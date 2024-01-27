/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Flipping Game

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<int> pref(n + 1), suff(n + 2);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + A[i];
    }
    for (int i = n; i > 0; i--) {
        suff[i] = suff[i + 1] + A[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int cur = pref[i - 1] + (j - i + 1) - (pref[j] - pref[i - 1]) + suff[j + 1];
            ans = max(ans, cur);
        }
    }
    cout << ans << nl;
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
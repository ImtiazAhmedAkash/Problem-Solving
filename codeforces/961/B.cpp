/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Lecture Sleep

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
    int n, k;
    cin >> n >> k;
    vector<int> theorem(n + 1), wake(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> theorem[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> wake[i];
        if (wake[i]) {
            ans += theorem[i];
            theorem[i] = 0;
        }
    }
    vector<int> pref(n + 1);
    partial_sum(theorem.begin(), theorem.end(), pref.begin());
    int add = 0;
    for (int i = 1; i + k - 1 <= n; i++) {
        int cur = pref[i + k - 1] - pref[i - 1];
        add = max(add, cur);
    }
    cout << ans + add << nl;
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
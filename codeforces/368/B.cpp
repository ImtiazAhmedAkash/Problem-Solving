/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sereja and Suffixes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<int> cnt(N), ans(n + 2);
    for (int i = n; i > 0; i--) {
        cnt[A[i]]++;
        ans[i] = ans[i + 1];
        if (cnt[A[i]] == 1) ans[i]++;
    }
    while (m--) {
        int x;
        cin >> x;
        cout << ans[x] << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Preparation for International Women's Day

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
    vector<int> cnt(k + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % k]++;
    }

    int ans = 0;

    ans += 2 * (cnt[0] / 2);

    for (int i = 1; i <= (k - 1) / 2; i++) {
        ans += 2 * min(cnt[i], cnt[k - i]);
    }

    if (k % 2 == 0) {
        ans += 2 * (cnt[k / 2] / 2);
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
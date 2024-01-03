/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Colorful Leaderboard

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
    vector<int> cnt(10);
    while (n--) {
        int x;
        cin >> x;
        cnt[min(8, x / 400)]++;
    }
    int least = 0;
    for (int i = 0; i < 8; i++) {
        least += (cnt[i] != 0);
    }
    cout << max(least, 1) << " " << least + cnt[8] << nl;
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
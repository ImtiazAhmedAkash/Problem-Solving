/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Problemsolving Log

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 3e5;

void solve() {
    vector<int> cnt(27);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto x : s) {
        cnt[x - 'A' + 1]++;
    }
    int ans = 0;
    for (int i = 1; i <= 26; i++) {
        if (cnt[i] >= i) ans++;
    }
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
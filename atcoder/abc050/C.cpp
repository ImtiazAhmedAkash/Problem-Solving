/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Lining Up

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    ll ans = 1;
    if (n & 1) {
        if (cnt[0] != 1) ans = 0;
        for (int i = 1; i < n; i++) {
            if ((i & 1) && cnt[i]) ans = 0;
            else if (i % 2 == 0 && cnt[i] == 2) ans = (ans * 2) % mod;
        }
    } else {
        if (cnt[0]) ans = 0;
        for (int i = 1; i < n; i++) {
            if ((i & 1) && cnt[i] == 2) ans = (ans * 2) % mod;
            else if (i % 2 == 0 && cnt[i]) ans = 0;
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
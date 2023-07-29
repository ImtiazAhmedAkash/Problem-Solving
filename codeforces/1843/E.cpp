/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tracking Segments

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> seg(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        seg[i] = {x, y};
    }
    int q;
    cin >> q;
    vector<int> chng(q);
    for (auto &x : chng) cin >> x;
    
    auto check = [&] (int mid) {
        vector<int> a(n + 1), pref(n + 2);
        for (int i = 0; i < mid; i++) a[chng[i]] = 1;
        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
        
        for (int i = 0; i < m; i++) {
            int l = seg[i].first, r = seg[i].second;
            if (pref[r] - pref[l - 1] >= ((r - l + 1) / 2) + 1) return true;
        }
        return false;
    };
    
    int L = 1, R = q + 1;
    while (L < R) {
        int M = L + (R - L) / 2;
        if (check(M)) R = M;
        else L = M + 1;
    }
    if (L > q) L = -1;
    cout << L << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
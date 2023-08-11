/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Deep Down Below

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int min_power_needed = 0;
        for (int j = 0; j < k; j++) {
            int x; 
            cin >> x;
            min_power_needed = max(min_power_needed, x - j + 1);
        }
        int profit = k;
        a.push_back({min_power_needed, profit});
    }
    sort(a.begin(), a.end());

    auto check = [&](int mid) {
        for (auto &[x, y] : a) {
            if (x > mid) return false;
            mid += y;
        }
        return true;
    };

    int L = 0, R = 1e9 + 10;
    while (L < R) {
        int M = L + (R - L) / 2;
        if (check(M)) R = M;
        else L = M + 1;
    }
    cout << L << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
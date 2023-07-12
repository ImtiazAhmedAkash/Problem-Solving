/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Ropes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    
    auto check = [&] (double mid) {
        int res = 0;
        for (auto x : a) {
            res += floor(x / mid);
            if (res >= k) return true;
        }
        return false;
    };
    
    double lo = 0, hi = 1e8;
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(9) << lo << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
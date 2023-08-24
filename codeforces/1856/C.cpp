/*  In the Name of ALLAH, the most gracious, the most merciful  */

// To Become Max

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    
    auto check = [&] (int mid) {
        for (int i = 0; i < n; i++) {
            bool possible = true;
            ll moves = 0, cur_min = mid;
            for (int j = i; j < n; j++, cur_min--) {
                if (a[j] >= cur_min) break;
                moves += cur_min - a[j];
                if (j + 1 == n) possible = false;
            }
            if (possible && moves <= k) return true;
        }
        return false;
    };
    
    int L = 0, R = 1e9;
    while (L < R) {
        int M = L + (R - L + 1) / 2;
        if (check(M)) L = M;
        else R = M - 1;
    }
    cout << R << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Medicine

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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    
    auto check = [&] (int mid) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= mid) {
                total += b[i];
            }
            if (total > k) return false;
        }
        return true;
    };
    
    int l = 1, r = INF;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
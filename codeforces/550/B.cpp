/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Preparing Olympiad

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
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> A(n);
    for(auto &it : A) {
        cin >> it;
    }
    
    auto check = [&](int mask) {
        int difficulty = 0, maxi = -inf, mini = inf;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                difficulty += A[i];
                maxi = max(maxi, A[i]);
                mini = min(mini, A[i]);
            }
        }
        return l <= difficulty && difficulty <= r && x <= maxi - mini;
    };
    
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (check(mask)) ans++;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Be Together

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int mini = *min_element(a.begin(), a.end());
    int maxi = *max_element(a.begin(), a.end());
    int ans = INF;
    for (int i = mini; i <= maxi; i++) {
        int cur = 0;
        for (auto x : a) {
            int diff = abs(i - x);
            cur += (diff * diff);
        }
        ans = min(ans, cur);
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
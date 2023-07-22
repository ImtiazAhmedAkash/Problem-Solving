/*  In the Name of ALLAH, the most gracious, the most merciful  */

// We Were Both Children

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
    vector<int> cnt (n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= n) cnt[x]++;
    }
    
    vector<int> factor(n + 1);
    // i is a factor of j
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            factor[j] += cnt[i];
        }
    }
    int ans = *max_element(factor.begin(), factor.end());
    cout << ans << nl;
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
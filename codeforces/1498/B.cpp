/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Box Fitting

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, W;
    cin >> n >> W;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    int ans = 1, cur = 0;
    while(!ms.empty()) {
        int rem = W - cur;
        auto it = ms.upper_bound(rem);
        if (it == ms.begin()) {
            cur = 0;
            ans++;
        } else {
            it--;
            cur += *it;
            ms.erase(it);
        }
    }
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
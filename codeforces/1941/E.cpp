/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rudolf and k Bridges

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
    int n, m, k, d;
    cin >> n >> m >> k >> d;

    vector<int> A(m);
    vector<ll> cost(n);
    vector<ll> support(m);
    for (int i = 0; i < n; i++) {
        for (auto& x : A) cin >> x;

        // Find minimum cost to install a support at row 'i'
        support.back() = 1;
        multiset<ll> ms = {1};
        int indx = max(0, m - 2 - d);
        for (int j = m - 2; j >= indx; j--) {
            support[j] = A[j] + 1 + support.back();
            ms.insert(support[j]);
        }

        for (int j = indx - 1; j >= 0; j--) {
            ms.erase(ms.find(support[j + d + 2]));
            support[j] = A[j] + 1 + *ms.begin();
            ms.insert(support[j]);
        }
        cost[i] = support.front();
    }

    ll ans = INF, cur = 0;
    for (int i = 0; i < k; i++) {
        cur += cost[i];
    }
    ans = min(ans, cur);
    for (int i = k; i < n; i++) {
        cur += cost[i];
        cur -= cost[i - k];
        ans = min(ans, cur);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
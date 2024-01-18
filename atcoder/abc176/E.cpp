/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bomber

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
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> R(h + 1), C(w + 1);
    vector A(h + 1, vector<int>());
    while (m--) {
        int x, y;
        cin >> x >> y;
        R[x]++, C[y]++;
        A[x].push_back(y);
    }
    int ans = 0;
    multiset<int> ms;
    for (int i = 1; i <= w; i++) {
        ms.insert(C[i]);
    }
    for (int i = 1; i <= h; i++) {
        for (auto x : A[i]) {
            ms.erase(ms.find(C[x]));
            ms.insert(C[x] - 1);
        }
        int cur = R[i] + (*ms.rbegin());
        ans = max(ans, cur);
        for (auto x : A[i]) {
            ms.erase(ms.find(C[x] - 1));
            ms.insert(C[x]);
        }
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
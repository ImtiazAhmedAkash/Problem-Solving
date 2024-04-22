/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Liebig's Barrels

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
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> A(n * k);
    for (auto& x : A) cin >> x;
    int mini = *min_element(A.begin(), A.end());

    vector<int> B, C;
    for (auto x : A) {
        if (x <= mini + l) B.push_back(x);
        else C.push_back(x);
    }

    if (B.size() < n) {
        cout << 0 << nl;
        return;
    }

    sort(B.begin(), B.end());
    ll ans = 0;
    while (B.size() || C.size()) {
        int cnt = min((int)C.size(), k - 1);
        for (int i = 0; i < cnt; i++) {
            C.pop_back();
        }
        int cur = inf;
        for (cnt; cnt < k; cnt++) {
            cur = min(cur, B.back());
            B.pop_back();
        }
        ans += cur;
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
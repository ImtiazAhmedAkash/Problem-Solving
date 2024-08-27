/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Turtle and a MEX Problem (Easy Version)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

ll range_sum(ll l, ll r) {
    if (r < l) return 0;
    ll x = r * (r + 1) / 2;
    ll y = l * (l - 1) / 2;
    return x - y;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int best = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        set<int> st;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            st.insert(x);
        }

        int mex = 0;
        while (st.find(mex) != st.end()) mex++;
        mex++;
        while (st.find(mex) != st.end()) mex++;

        best = max(best, mex);
    }

    ll ans = 1LL * (min(m, best) + 1) * best;
    ans += range_sum(min(m, best) + 1, m);
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
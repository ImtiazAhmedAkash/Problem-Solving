/*  In the Name of ALLAH, the most gracious, the most merciful  */

// A-B Knapsack

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
    ll n, m, s, a, b;
    cin >> n >> m >> s >> a >> b;
    vector<ll> A(n + 1), Pa(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sort(A.begin() + 1, A.end(), greater());
    partial_sum(A.begin(), A.end(), Pa.begin());
    vector<ll> B(m + 1), Pb(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }
    sort(B.begin() + 1, B.end(), greater());
    partial_sum(B.begin(), B.end(), Pb.begin());
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll wt = a * i;
        if (wt > s) break;
        ll x = min(m, (s - wt) / b);
        ans = max(ans, Pa[i] + Pb[x]);
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
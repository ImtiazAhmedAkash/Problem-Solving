/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Zero-Sum Prefixes

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
    int n;
    cin >> n;
    vector<int> A(n + 1);
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pref[i] = pref[i - 1] + A[i];
    }

    int ans = 0;
    int best = 0;
    map<ll, int> M;
    for (int i = n; i > 0; i--) {
        M[pref[i]]++;
        best = max(best, M[pref[i]]);
        if (A[i] == 0) {
            ans += best;
            best = 0;
            M.clear();
        }
    }
    ans += M[0];

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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 21—0?

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
    int n, k;
    cin >> n >> k;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<ll> B(n + 1);
    ll sum = 0;
    for (int i = 1; i < k; i++) {
        B[i] = A[i] - sum;
        sum += B[i];
    }
    for (int i = k; i <= n; i++) {
        B[i] = A[i] - sum;
        sum -= B[i - k + 1];
        sum += B[i];
    }

    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (B[i]) {
            cnt++;
            ans = max(ans, cnt);
        } else {
            cnt = 0;
        }
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
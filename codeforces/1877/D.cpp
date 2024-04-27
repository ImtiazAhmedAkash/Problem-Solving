/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Effects of Anti Pimples

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<int> Max(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            Max[i] = max(Max[i], A[j]);
        }
    }
    sort(Max.begin(), Max.end());

    int ans = 0;
    int power = 1;
    for (int i = 1; i <= n; i++) {
        int cur = (1LL * Max[i] * power) % mod;
        ans = (0LL + ans + cur) % mod;
        power = (1LL * power * 2) % mod;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Little Girl and Maximum Sum

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
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<int> freq(n + 2);
    while (q--) {
        int l, r;
        cin >> l >> r;
        freq[l]++, freq[r + 1]--;
    }
    partial_sum(freq.begin(), freq.end(), freq.begin());
    freq.pop_back();
    sort(freq.begin(), freq.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * A[i] * freq[i];
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Another Sigma Problem

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void solve() {
    int n;
    cin >> n;
    vector<string> A(n);
    vector<int> cnt(15);
    for (auto& x : A) {
        cin >> x;
        cnt[x.size()]++;
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * i * stoll(A[i]);
        ans %= mod;
        cnt[A[i].size()]--;
        ll mult = 10;
        for (int j = 1; j <= 10; j++, mult *= 10) {
            ans += 1LL * mult * cnt[j] % mod * stoll(A[i]);
            ans %= mod;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rock and Lever

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * (A & B) >= (A ^ B) if and only if A's and B's highest bit match.
 * Keep a count of those number whose highest bit match.
 * n * (n - 1) / 2 pairs can be made from n numbers.
 * The answer is the total of such pairs.
 */

void solve() {
    int n;
    cin >> n;
    vector<ll> cnt(30);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[__lg(x)]++;
    }
    ll ans = 0;
    for (auto i : cnt) {
        ans += (i * (i - 1) / 2);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
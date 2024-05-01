/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Permutation Counting

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e14;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> A(n);
    for (auto& x : A) cin >> x;

    auto check = [&](ll mid) -> bool {
        ll need = 0;
        for (int i = 0; i < n; i++) {
            need += max(0LL, mid - A[i]);
            if (k < need) return false;
        }
        return true;
    };

    ll L = 0, R = INF;
    while (L < R) {
        ll M = L + (R - L + 1) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (R < A[i]) {
            cnt++;
        } else {
            k -= R - A[i];
        }
    }
    // R = number of full permutations possible, i.e. we can have at least 'R' cards of each number from 1 to n
    ll ans = 1LL * n * (R - 1) + 1;
    ans += cnt + k;
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
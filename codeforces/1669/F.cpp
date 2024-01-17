/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Eating Candies

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    int ans = 0, cur = 0;
    int alice = 0, bob = 0;
    for (int l = 0, r = n - 1; l <= r;) {
        if (alice <= bob) {
            alice += A[l];
            l++;
        } else {
            bob += A[r];
            r--;
        }
        cur++;
        if (alice == bob) {
            ans = max(ans, cur);
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
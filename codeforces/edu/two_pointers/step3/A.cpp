/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Looped Playlist

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
    ll p;
    cin >> p;
    vector<int> A(n);
    ll sum = 0;
    for (auto &x : A) {
        cin >> x;
        sum += x;
    }
    for (int i = 0; i < n; i++) {
        A.push_back(A[i]);
    }
    ll ans = n * (p / sum);
    p %= sum;
    int start = 0;
    sum = 0;
    int extra = inf;
    for (int l = 0, r = 0; r < 2 * n; r++) {
        sum += A[r];
        while (l <= r && sum - A[l] >= p) {
            sum -= A[l];
            l++;
        }
        if (sum >= p && extra > r - l + 1) {
            extra = r - l + 1;
            start = l;
        }
    }
    cout << (start % n) + 1 << " " << ans + extra << nl;
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
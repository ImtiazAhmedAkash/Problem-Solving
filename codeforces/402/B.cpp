/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Trees in a Row

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
    vector<int> A(n);
    for (auto &x : A) {
        cin >> x;
    }

    int ans = inf, start = 0;
    for (int x = 1; x <= 1000; x++) {
        int op = 0;
        int height = x;
        for (int i = 0; i < n; i++) {
            if (A[i] != height) op++;
            height += k;
        }
        if (op < ans) {
            ans = op;
            start = x;
        }
    }

    cout << ans << nl;
    for (int i = 0, cur = start; i < n; i++, cur += k) {
        if (A[i] < cur) {
            cout << "+ " << i + 1 << " " << cur - A[i] << nl;
        } else if (A[i] > cur) {
            cout << "- " << i + 1 << " " << A[i] - cur << nl;
        }
    }
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
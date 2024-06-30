/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bingo 2

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
    vector<int> col(n + 1), row(n + 1);
    int left = 0, right = 0;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        int c = (x % n);
        if (c == 0) c += n;
        col[c]++;
        int r = (x + n - 1) / n;
        row[r]++;
        if ((x - 1) % (n + 1) == 0 && (x - 1) / (n + 1) + 1 > 0 && (x - 1) / (n + 1) + 1 <= n) left++;
        if ((x - n) % (n - 1) == 0 && (x - n) / (n - 1) + 1 > 0 && (x - n) / (n - 1) + 1 <= n) right++;
        if (col[c] == n || row[r] == n || left == n || right == n) {
            cout << i << nl;
            return;
        }
    }
    cout << -1 << nl;
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
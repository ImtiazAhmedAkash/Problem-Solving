/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Field Division (easy version)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int lx = n, ly = m;
    vector<pair<int, int>> A(k);
    map<pair<int, int>, int> M;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        A[i] = {x, y};
        M[A[i]] = i;
        if (x == lx) {
            ly = min(ly, y - 1);
        }
    }

    sort(A.begin(), A.end(), [&](pair<int, int> x, pair<int, int> y) {
        if (x.first == y.first) return x.second < y.second;
        return x.first > y.first;
    });

    vector<int> ans(k);
    ll tot = 0;

    // If there are any fountain in the last row, the leftmost fountain will increase the plot size.
    if (ly != m) {
        ans[M[{lx, ly + 1}]] = 1;
    }

    for (auto [x, y] : A) {
        if (ly < y) continue;
        tot += 1LL * (lx - x) * ly;
        ans[M[{x, y}]] = 1;
        lx = x;
        ly = y - 1;
    }
    tot += 1LL * lx * ly;

    cout << tot << nl;
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
    cout << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Make Nonzero Sum (hard version)

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
    for (auto& x : A) cin >> x;

    vector<int> nxt(n);
    int cur = n;
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = cur;
        if (A[i] != 0) cur = i;
    }

    vector<pair<int, int>> ans;
    for (int l = 0; l < n; ) {
        if (A[l] == 0) {
            ans.push_back({l, l});
            l++;
            continue;
        }
        int r = nxt[l];
        if (r == n) {
            ans.push_back({l, r - 1});
            l = r;
            continue;
        }
        if (A[l] == A[r]) {
            if (l % 2 != r % 2) {
                ans.push_back({l, r});
            } else {
                ans.push_back({l, r - 2});
                ans.push_back({r - 1, r});
            }
        } else {
            if (l % 2 == r % 2) {
                ans.push_back({l, r});
            } else {
                ans.push_back({l, r - 1});
                ans.push_back({r, r});
            }
        }
        l = r + 1;
    }

    int sum = 0;
    for (auto [x, y] : ans) {
        bool add = true;
        for (int i = x; i <= y; i++) {
            if (add)
                sum += A[i];
            else
                sum -= A[i];
            add = !add;
        }
    }

    if (sum) {
        cout << -1 << nl;
        return;
    }

    cout << ans.size() << nl;
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << nl;
    }
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
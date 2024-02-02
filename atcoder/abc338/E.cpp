/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Chords

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
    vector<pair<int, int>> A(2 * n + 1);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y < x) swap(x, y);
        A[x] = {0, i};  // A[i].first = 0 -> starting of a segment, 1 -> ending of a segment
        A[y] = {1, i};  // A[i].second -> marker of same segment
    }
    stack<int> stk;
    for (int i = 1; i <= 2 * n; i++) {
        auto [x, y] = A[i];
        if (x == 0) {
            stk.push(y);
            continue;
        }
        if (stk.top() != y) {
            cout << "Yes" << nl;
            return;
        }
        stk.pop();
    }
    cout << "No" << nl;
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
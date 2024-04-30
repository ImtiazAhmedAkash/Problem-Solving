/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Min Max Sort

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
    vector<int> A(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        pos[A[i]] = i;
    }

    auto check = [&](int mid) -> bool {
        for (int i = mid; i + 1 <= n - mid + 1; i++) {
            if (pos[i] > pos[i + 1]) return false;
        }
        return true;
    };

    int L = 0, R = (n + 1) / 2;
    while (L < R) {
        int M = L + (R - L + 1) / 2;
        if (check(M)) {
            R = M - 1;
        } else {
            L = M;
        }
    }
    cout << R << nl;
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
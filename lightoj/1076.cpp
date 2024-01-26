/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1076 - Get the Containers

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
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    auto check = [&](int mid) -> bool {
        int box = 1, cur = 0;
        for (int i = 0; i < n; i++) {
            if (mid < A[i]) return false;
            if (mid < cur + A[i]) {
                box++;
                cur = A[i];
            } else {
                cur += A[i];
            }
        }
        return box <= m;
    };

    int L = 1, R = inf;
    while (L < R) {
        int M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }
    cout << L << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}
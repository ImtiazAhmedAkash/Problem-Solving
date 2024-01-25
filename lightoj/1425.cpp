/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1425 - The Monkey and the Oiled Bamboo

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    auto check = [&](int mid) -> bool {
        for (int i = 1; i <= n; i++) {
            int diff = A[i] - A[i - 1];
            if (diff > mid) return false;
            if (diff == mid) mid--;
        }
        return true;
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
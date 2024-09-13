/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Watering an Array

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
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<int> B(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> B[i];
    }
    for (int i = 0; B.size() <= 2 * n; i++) {
        B.push_back(B[(i % k) + 1]);
    }

    auto check = [&]() -> int {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i] == i) res++;
        }
        return res;
    };

    int ans = 0;

    for (int op = 0; op <= min(2 * n, d - 1); op++) {
        for (int i = 1; i <= B[op]; i++) {
            A[i]++;
        }
        int cur = check() + (d - (op + 1)) / 2;
        ans = max(ans, cur);
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
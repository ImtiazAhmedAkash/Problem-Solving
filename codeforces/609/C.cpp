/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Load Balancing

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
    int sum = 0;
    vector<int> A(n);
    for (auto& x : A) {
        cin >> x;
        sum += x;
    }
    sort(A.begin(), A.end(), greater());

    int need = sum / n;
    int ans = 0;
    if (sum % n == 0) {
        for (auto& x : A) {
            ans += max(0, x - need);
        }
    } else {
        int big = sum % n;
        for (int i = 0; i < big; i++) {
            ans += max(0, A[i] - (need + 1));
        }
        for (int i = big; i < n; i++) {
            ans += max(0, A[i] - need);
        }
    }
    cout << ans << nl;
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
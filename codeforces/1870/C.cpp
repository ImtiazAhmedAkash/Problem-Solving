/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Colorful Table

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
    vector<int> A(n), cnt(k + 1), L(k + 1), R(k + 1);
    for (auto &x : A) {
        cin >> x;
        cnt[x]++;
    }
    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (A[i] >= cur) {
            for (int j = cur; j <= A[i]; j++) {
                L[j] = i;
            }
            cur = A[i] + 1;
        }
    }
    cur = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] >= cur) {
            for (int j = cur; j <= A[i]; j++) {
                R[j] = i;
            }
            cur = A[i] + 1;
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << (cnt[i] ? 2 * (R[i] - L[i] + 1) : 0) << " ";
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
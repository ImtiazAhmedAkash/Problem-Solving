/*  In the Name of ALLAH, the most gracious, the most merciful  */

// K Swap

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    for (int i = 0; i < k; i++) {
        vector<int> B;
        for (int j = i; j < n; j += k) {
            B.push_back(A[j]);
        }
        sort(B.begin(), B.end());
        for (int j = 0, l = i; j < B.size(); j++, l += k) {
            A[l] = B[j];
        }
    }
    cout << (is_sorted(A.begin(), A.end()) ? "Yes" : "No") << nl;
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
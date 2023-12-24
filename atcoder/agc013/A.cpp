/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 3e5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    A.erase(unique(A.begin(), A.end()), A.end());
    n = A.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && A[i] < A[i + 1]) {
            while (i + 1 < n && A[i] < A[i + 1]) {
                i++;
            }
        } else if (i + 1 < n && A[i] > A[i + 1]) {
            while (i + 1 < n && A[i] > A[i + 1]) {
                i++;
            }
        }
        ans++;
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
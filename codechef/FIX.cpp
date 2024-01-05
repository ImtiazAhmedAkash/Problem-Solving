/*  In the Name of ALLAH, the most gracious, the most merciful  */

// FIX - Prefixing

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
    for (auto &x : A) cin >> x;
    int most = *max_element(A.begin(), A.end());
    map<int, int> M;
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        if (M.find(A[i]) == M.end()) {
            B[i] = A[i];
            M[A[i]] = 1;
        } else {
            B[i] = most;
        }
    }
    for (auto x : B) cout << x << " ";
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
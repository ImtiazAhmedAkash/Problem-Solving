/*  In the Name of ALLAH, the most gracious, the most merciful  */

// GAME_XI - GAME 11

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
    vector<int> A(n), B(m);
    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;

    if (n < 4 || m < 4 || n + m < 11) {
        cout << -1 << nl;
        return;
    }

    sort(A.begin(), A.end(), greater());
    sort(B.begin(), B.end(), greater());
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += A[i] + B[i];
    }

    vector<int> C;
    for (int i = 4; i < A.size(); i++) {
        C.push_back(A[i]);
    }
    for (int i = 4; i < B.size(); i++) {
        C.push_back(B[i]);
    }
    sort(C.begin(), C.end(), greater());
    for (int i = 0; i < 3; i++) {
        ans += C[i];
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
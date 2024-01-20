/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Three Activities

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
    vector<pair<int, int>> A(n), B(n), C(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A[i] = {x, i};
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        B[i] = {x, i};
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        C[i] = {x, i};
    }
    sort(A.begin(), A.end(), greater());
    sort(B.begin(), B.end(), greater());
    sort(C.begin(), C.end(), greater());
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i].second == B[j].second) continue;
            for (int k = 0; k < 3; k++) {
                if (A[i].second == C[k].second || B[j].second == C[k].second) continue;
                ans = max(ans, A[i].first + B[j].first + C[k].first);
            }
        }
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
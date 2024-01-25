/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1198 - Karate Competition

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
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = 0;
    int La = 0, Lb = 0, Ra = n - 1, Rb = n - 1;
    while (La <= Ra) {
        if (B[Rb] < A[Ra]) {
            ans += 2;
            Ra--, Rb--;
            continue;
        }
        if (A[Ra] < B[Rb]) {
            La++, Rb--;
            continue;
        }
        // A[Ra] == B[Rb]
        if (B[Lb] < A[La]) {
            ans += 2;
            La++, Lb++;
        } else {
            if (A[La] == B[Rb]) ans++;
            La++, Rb--;
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
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}
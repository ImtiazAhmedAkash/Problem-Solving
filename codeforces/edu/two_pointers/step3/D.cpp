/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Stylish clothes

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
    cin >> n;
    vector<int> B(n);
    for (auto &x : B) cin >> x;
    cin >> n;
    vector<int> C(n);
    for (auto &x : C) cin >> x;
    cin >> n;
    vector<int> D(n);
    for (auto &x : D) cin >> x;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());

    auto valid = [&](int a, int b, int c, int d) -> bool {
        return a < A.size() && b < B.size() && c < C.size() && d < D.size();
    };

    int diff = inf;
    int ansa = -1, ansb = -1, ansc = -1, ansd = -1;
    for (int a = 0, b = 0, c = 0, d = 0; valid(a, b, c, d);) {
        int mx = max({A[a], B[b], C[c], D[d]});
        int mn = min({A[a], B[b], C[c], D[d]});
        if (mx - mn < diff) {
            diff = mx - mn;
            ansa = A[a], ansb = B[b], ansc = C[c], ansd = D[d];
        }
        if (mn == A[a])
            a++;
        else if (mn == B[b])
            b++;
        else if (mn == C[c])
            c++;
        else
            d++;
    }
    cout << ansa << " " << ansb << " " << ansc << " " << ansd << nl;
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
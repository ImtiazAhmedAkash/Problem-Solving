/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// ONETOTHREE - One To Three

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 2; i < n; i++) {
        if (A[i - 1] + A[i + 1] == 4 && A[i] == 3) {
            A[i] = 1;
        }
    }

    for (int i = n - 1; i > 1; i--) {
        if (A[i - 1] + A[i + 1] == 4 && A[i] == 3) {
            A[i] = 1;
        }
    }

    cout << accumulate(A.begin(), A.end(), 0LL) << nl;
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
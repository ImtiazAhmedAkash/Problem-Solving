/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// TWOCARD - Two Cards

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
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> A[i].second;
    }

    sort(A.begin(), A.end(), greater());

    int b = 0;
    for (int i = 2; i < n; i++) {
        b = max(b, A[i].second);
    }
    int a = max(A[0].first, A[0].second);
    int c = max(A[1].first, A[1].second);

    cout << (b > a || a != c ? "Yes" : "No") << nl;
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
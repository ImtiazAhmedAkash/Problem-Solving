/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Max Plus Size

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
    vector<int> A, B;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i & 1) {
            A.push_back(x);
        } else {
            B.push_back(x);
        }
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = A.back() + (int)A.size();
    if (!B.empty()) {
        ans = max(ans, B.back() + (int)B.size());
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
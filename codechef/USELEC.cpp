/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// USELEC - Elections

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
    vector<int> B(n);
    for (auto &x : B) cin >> x;

    int cnt = 0;
    vector<int> extra;
    for (int i = 0; i < n; i++) {
        if (A[i] > B[i]) {
            cnt++;
        } else {
            extra.push_back(B[i] - A[i] + 1);
        }
    }

    sort(extra.begin(), extra.end());

    for (int i = 0; i < extra.size(); i++) {
        if (extra[i] <= k) {
            cnt++;
            k -= extra[i];
        }
    }

    cout << (cnt >= (n + 1) / 2 ? "YES" : "NO") << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Make Them Equal

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
    sort(A.begin(), A.end());

    int diff = A.back() - A.front();

    vector<int> div;
    div.push_back(0);
    for (int i = 1; i * i <= diff; i++) {
        if (diff % i == 0) {
            div.push_back(i);
            if (i != diff / i) {
                div.push_back(diff / i);
            }
        }
    }

    int ans = inf;
    for (auto &x : div) {
        int target = A.front() + x;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (A[i] != target and A[i] + x != target and A[i] - x != target) {
                ok = false;
            }
        }
        if (ok) {
            ans = min(ans, x);
        }
    }

    cout << (ans == inf ? -1 : ans) << nl;
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
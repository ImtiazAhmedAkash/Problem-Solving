/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sequence Game

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> ans;
    ans.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ans.push_back(a[i]);
        }
        ans.push_back(a[i]);
    }
    cout << ans.size() << nl;
    for (auto x : ans) cout << x << " ";
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
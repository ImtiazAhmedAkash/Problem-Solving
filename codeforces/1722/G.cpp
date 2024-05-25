/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Even-Odd XOR

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<vector<int>> A = {
    {2, 1, 3, 0},
    {2, 0, 4, 5, 3},
    {4, 1, 2, 12, 3, 8},
    {2, 1, 3},
};

void solve() {
    int n;
    cin >> n;
    vector<int> ans = A[n % 4];
    n -= ans.size();
    for (int i = 0; i < n; i++) {
        ans.push_back(16 + i);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
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
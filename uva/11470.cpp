/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 11470 - Square Sums

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
    int n, T = 1;
    while (cin >> n && n) {
        vector<vector<int>> A(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> A[i][j];
            }
        }
        vector<int> ans((n + 1) / 2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int indx = min({i, j, n - 1 - i, n - 1 - j});
                ans[indx] += A[i][j];
            }
        }
        cout << "Case " << T++ << ": ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " \n"[i + 1 == ans.size()];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
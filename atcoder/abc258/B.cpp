/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Number Box

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<int> dx = {-1, +0, +1, +0, -1, -1, +1, +1};
vector<int> dy = {+0, +1, +0, -1, -1, +1, -1, +1};

void solve() {
    int n;
    cin >> n;
    vector<string> A(n);
    for (auto& x : A) cin >> x;

    string ans(n, '0');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 8; k++) {
                string cur = "";
                int nx = i, ny = j;
                for (int t = 0; t < n; t++) {
                    cur += A[nx][ny];
                    nx = (nx + dx[k] + n) % n;
                    ny = (ny + dy[k] + n) % n;
                }
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << nl;
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
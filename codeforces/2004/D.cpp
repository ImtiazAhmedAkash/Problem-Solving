/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Colored Portals

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
    int n, q;
    cin >> n >> q;
    vector<string> A(n + 1);
    map<string, vector<int>> M;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sort(A[i].begin(), A[i].end());
        M[A[i]].push_back(i);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << 0 << nl;
            continue;
        }

        if (x > y) swap(x, y);
        string s = A[x];
        string t = A[y];
        if (s[0] == t[0] || s[0] == t[1] || s[1] == t[0] || s[1] == t[1]) {
            cout << y - x << nl;
            continue;
        }

        int ans = inf;
        vector<char> col = {'B', 'G', 'R', 'Y'};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                string str;
                str += s[i];
                if (col[j] == str[0]) continue;
                str += col[j];
                sort(str.begin(), str.end());
                if (M.find(str) == M.end()) continue;

                if (str[0] == t[0] || str[0] == t[1] || str[1] == t[0] || str[1] == t[1]) {
                    vector<int> X;
                    auto it = upper_bound(M[str].begin(), M[str].end(), x);
                    if (it != M[str].end()) {
                        X.push_back(*it);
                    }
                    if (it != M[str].begin()) {
                        X.push_back(*prev(it));
                    }

                    for (int k = 0; k < X.size(); k++) {
                        ans = min(ans, abs(x - X[k]) + abs(y - X[k]));
                    }
                }
            }
        }
        cout << (ans == inf ? -1 : ans) << nl;
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
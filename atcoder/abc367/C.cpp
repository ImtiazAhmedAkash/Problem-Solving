/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Enumerate Sequences

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
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    auto fun = [&](auto&& self, int indx, int sum, vector<int> B) {
        if (indx == n) {
            if (sum % k == 0) {
                for (int i = 0; i < n; i++) {
                    cout << B[i] << " \n"[i + 1 == n];
                }
            }
            return;
        }
        for (int i = 1; i <= A[indx]; i++) {
            B.push_back(i);
            self(self, indx + 1, sum + i, B);
            B.pop_back();
        }
    };

    fun(fun, 0, 0, vector<int>());
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
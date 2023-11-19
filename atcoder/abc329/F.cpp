/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Colored Ball

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
    vector<set<int>> A(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        A[i].insert(x);
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (A[a].size() > A[b].size()) {
            swap(A[a], A[b]);
        }
        for (auto x : A[a]) {
            A[b].insert(x);
        }
        A[a].clear();
        cout << A[b].size() << nl;
    }
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
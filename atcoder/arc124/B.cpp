/*  In the Name of ALLAH, the most gracious, the most merciful  */

// XOR Matching 2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e6;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;

    set<int> ans;
    for (int i = 0; i < n; i++) {
        int x = A[0] ^ B[i];
        multiset<int> ms;
        for (int j = 0; j < n; j++) {
            ms.insert(B[j]);
        }

        for (int j = 0; j < n; j++) {
            auto it = ms.find(A[j] ^ x);
            if (it == ms.end()) break;
            ms.erase(it);
        }
        if (ms.empty()) {
            ans.insert(x);
        }
    }

    cout << ans.size() << nl;
    for (auto x : ans) {
        cout << x << nl;
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
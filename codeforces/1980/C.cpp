/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sofia and the Lost Operationss

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
    vector<int> A(n), B(n);
    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;
    int m;
    cin >> m;
    vector<int> C(m);
    for (auto& x : C) cin >> x;

    map<int, int> need;
    map<int, int> present;
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            need[B[i]]++;
        } else {
            present[B[i]] = 1;
        }
    }

    int bad = 0;
    for (int i = 0; i < m; i++) {
        if (need.find(C[i]) != need.end()) {
            need[C[i]]--;
            present[C[i]] = 1;
            bad = 0;
            if (need[C[i]] == 0) {
                need.erase(C[i]);
            }
        } else if (present.find(C[i]) != present.end()) {
            bad = 0;
        } else {
            bad++;
        }
    }

    cout << ((bad || need.size() > 0) ? "NO" : "YES") << nl;
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
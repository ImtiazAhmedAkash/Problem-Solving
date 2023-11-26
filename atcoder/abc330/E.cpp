/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Mex and Update

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
    set<int> S;
    for (int i = 0; i <= n; i++) {
        S.insert(i);
    }
    vector<int> A(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] > n) continue;
        cnt[A[i]]++;
        if (cnt[A[i]] == 1) S.erase(A[i]);
    }
    while (q--) {
        int i, x;
        cin >> i >> x;
        if (A[i] <= n) {
            cnt[A[i]]--;
            if (cnt[A[i]] == 0) {
                S.insert(A[i]);
            }
        }
        A[i] = x;
        if (A[i] <= n) {
            cnt[A[i]]++;
            if (cnt[A[i]] == 1) {
                S.erase(A[i]);
            }
        }
        cout << *S.begin() << nl;
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
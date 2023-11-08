/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Two Out of Three

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 105;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), cnt(N, 0);
    set<int> S;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        cnt[A[i]]++;
        if (cnt[A[i]] == 2 && S.size() != 2) S.insert(i);
    }

    if (S.size() != 2) {
        cout << -1 << nl;
        return;
    }

    vector<int> B(n, 1);
    B[*(S.begin())] = 2;
    B[*(S.rbegin())] = 3;

    for (auto x : B) cout << x << " ";
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
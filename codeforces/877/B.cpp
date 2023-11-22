/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Nikita and string

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
    string s;
    cin >> s;
    int n = s.size();
    s = "+" + s;
    vector<int> A(n + 2), B(n + 2);
    for (int i = 1; i <=n; i++) {
        if (s[i] == 'a') A[i] = 1;
        else B[i] = 1;
    }
    partial_sum(A.begin(), A.end(), A.begin());
    partial_sum(B.begin(), B.end(), B.begin());
    int ans = inf;
    for (int i = 0; i <= n; i++) {
        for (int j = n + 1; j > i; j--) {
            int cur = (B[i] - B[0]) + (A[j - 1] - A[i]) + (B[n + 1] - B[j - 1]);
            ans = min(ans, cur);
        }
    }
    cout << n - ans << nl;
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
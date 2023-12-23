/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Gift Tax

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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    auto check = [&](int mid) {
        ll have = 0;
        for (int i = 0; i < n; i++) {
            have += max(0, (A[i] - mid) / b);
        }
        ll need = 0;
        for (int i = 0; i < n; i++) {
            need += (max(0, mid - A[i]) + a - 1) / a;
        }
        return need <= have;
    };
    
    int L = 0, R = inf;
    while (L < R) {
        int M = L + (R - L + 1) / 2;
        if (check(M)) L = M;
        else R = M - 1;
    }
    cout << R << nl;
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
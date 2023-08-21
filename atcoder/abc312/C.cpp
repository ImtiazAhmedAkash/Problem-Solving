/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Invisible Hand

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n), b(m);
    for (auto &x : s) cin >> x;
    for (auto &x : b) cin >> x;
    
    auto check = [&] (int mid) {
        int buyer = 0, seller = 0;
        for (auto x : s) {
            if (x <= mid) seller++;
        }
        for (auto x : b) {
            if (x >= mid) buyer++;
        }
        return seller >= buyer;
    };
    
    int L = 0, R = 1e9 + 10;
    while (L < R) {
        int M = L + (R - L) / 2;
        if (check(M)) R = M;
        else L = M + 1;
    }
    cout << L << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}
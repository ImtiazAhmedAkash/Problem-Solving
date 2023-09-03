/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Wooden Toy Festival

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    
    auto check = [&] (int mid) {
        int curver = 1;
        int x = a[0];
        for (int i = 0; i < n; i++) {
            int time = (a[i] - x + 1) / 2;
            if (time > mid) {
                curver++;
                x = a[i];
            }
        }
        return curver <= 3;
    };
    
    int L = 0, R = (int) 1e10;
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

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}
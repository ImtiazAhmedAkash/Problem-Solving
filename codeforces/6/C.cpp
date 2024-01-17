/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Alice, Bob and Chocolate

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    int a = 0, b = 0, at = 0, bt = 0;
    for (int l = 0, r = n - 1; l <= r;) {
        if (at <= bt) {
            at += A[l];
            a++, l++;
        } else {
            bt += A[r];
            b++, r--;
        }
    }
    cout << a << " " << b << nl;
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
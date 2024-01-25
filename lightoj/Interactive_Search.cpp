/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Interactive Search

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
    int L = 1, R = n;
    while (L <= R) {
        int M = L + (R - L) / 2;
        cout << "guess " << M << endl;
        string s;
        cin >> s;
        if (s == "high") {
            R = M - 1;
        } else if (s == "low") {
            L = M + 1;
        } else {
            break;
        }
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
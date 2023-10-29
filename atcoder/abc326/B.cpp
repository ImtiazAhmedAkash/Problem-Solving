/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 326-like Numbers

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
    while (true) {
        string s = to_string(n);
        int a = s[0] - '0';
        int b = s[1] - '0';
        int c = s[2] - '0';
        if (a * b == c) {
            cout << s << nl;
            break;
        }
        n++;
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
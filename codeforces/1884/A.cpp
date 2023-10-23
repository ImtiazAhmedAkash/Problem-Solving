/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Simple Design

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
    int x, k;
    cin >> x >> k;
    while (true) {
        string s = to_string(x);
        int sum = 0;
        for (auto it : s) {
            sum += it - '0';
        }
        if (sum % k == 0) {
            cout << s << nl;
            break;
        }
        x++;
    }
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
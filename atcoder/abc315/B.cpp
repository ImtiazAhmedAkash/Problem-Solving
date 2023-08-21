/*  In the Name of ALLAH, the most gracious, the most merciful  */

// The Middle Day

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int m;
    cin >> m;
    vector<int> a(m);
    for (auto &x : a) cin >> x;
    int total = accumulate(a.begin(), a.end(), 0);
    int s = (total + 1) / 2;
    int cur = 0;
    for (int i = 0; i < m ; i++) {
        if (cur + a[i] < s) cur += a[i];
        else {
            cout << i + 1 << " " << s - cur << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Mr. Perfectly Fine

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
    int one = inf, two = inf, both = inf;
    for (int i = 0; i < n; i++) {
        int m;
        string s;
        cin >> m >> s;
        if (s == "11") both = min(both, m);
        else if (s == "10") one = min(one, m);
        else if (s == "01") two = min(two, m);
    }
    
    int ans = min(one + two, both);
    cout << (ans >= inf ? -1 : ans) << nl;
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
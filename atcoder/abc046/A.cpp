/*  In the Name of ALLAH, the most gracious, the most merciful  */

// AtCoDeer and Paint Cans

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    set<int> s;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << nl;
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
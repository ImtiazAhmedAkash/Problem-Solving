/*  In the Name of ALLAH, the most gracious, the most merciful  */

// A - Only Pluses

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
    multiset<int> ms;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    for (int i = 0; i < 5; i++) {
        int x = *ms.begin();
        ms.erase(ms.begin());
        ms.insert(x + 1);
    }
    int ans = 1;
    while (!ms.empty()) {
        int x = *ms.begin();
        ms.erase(ms.begin());
        ans *= x;
    }
    cout << ans << nl;
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
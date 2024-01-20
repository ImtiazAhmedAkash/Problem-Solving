/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Distinct Buttons

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
    set<char> st;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x > 0) st.insert('R');
        else if (x < 0) st.insert('L');
        if (y > 0) st.insert('U');
        else if (y < 0) st.insert('D');
    }
    cout << (st.size() == 4 ? "NO" : "YES") << nl;
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
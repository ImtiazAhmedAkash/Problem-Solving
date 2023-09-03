/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Make Them Odd

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    set<int> st;
    while (n--) {
        int x;
        cin >> x;
        if (x % 2 == 0) st.insert(x);
    }
    while (!st.empty()) {
        int x = *(st.rbegin());
        st.erase(x);
        x = x >> 1;
        ans++;
        if (x % 2 == 0) st.insert(x);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
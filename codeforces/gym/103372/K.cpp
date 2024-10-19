/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Organizing Beads

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
    string s;
    cin >> s;

    set<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'O') {
            st.insert(i + 1);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (st.find(x) == st.end()) {
            st.insert(x);
        } else {
            st.erase(x);
        }

        int k = st.size();
        cout << min(*st.rbegin() - k, n - k + 1 - *st.begin()) << nl;
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
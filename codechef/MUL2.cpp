/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// MUL2 - Multiply 2 to Minimize

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    map<ll, int> mp;
    vector<int> ans(n);
    set<ll> st;
    for (int i = 0; i < n; i++) {
        mp[A[i]]++;
        if (mp[A[i]] > 1) {
            st.insert(A[i]);
        }
        while (!st.empty()) {
            auto x = *st.begin();
            st.erase(st.begin());
            int y = mp[x];
            mp[2 * x] += y / 2;
            if (mp[2 * x] > 1) {
                st.insert(2 * x);
            }
            mp[x] = y % 2;
            if (mp[x] == 0) {
                mp.erase(x);
            }
        }
        ans[i] = mp.size();
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
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
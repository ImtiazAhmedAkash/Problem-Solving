/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Alya and Permutation

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

    vector<int> ans(n);
    if (n == 5) {
        ans = {2, 1, 3, 4, 5};
    } else if (n == 6) {
        ans = {1, 2, 4, 6, 5, 3};
    } else if (n == 7) {
        ans = {2, 4, 5, 1, 3, 6, 7};
    } else {
        set<int> st;
        for (int i = 1; i <= n; i++) {
            st.insert(i);
        }
        int msb = __lg(n);
        if (n & 1) {
            ans[n - 1] = n;
            ans[n - 2] = (1 << msb);
            ans[n - 3] = ans[n - 2] - 1;
            ans[n - 4] = ans[n - 2] - 2;
            ans[n - 5] = 1;
            ans[n - 6] = 3;
            for (int i = 1; i <= 6; i++) {
                st.erase(ans[n - i]);
            }

            for (int i = 0; i < n - 6; i++) {
                ans[i] = *st.begin();
                st.erase(st.begin());
            }
        } else {
            ans[n - 1] = n;
            ans[n - 2] = (1 << msb) - 1;
            ans[n - 3] = ans[n - 2] - 1;
            ans[n - 4] = 1;
            ans[n - 5] = 3;
            for (int i = 1; i <= 5; i++) {
                st.erase(ans[n - i]);
            }

            for (int i = 0; i < n - 5; i++) {
                ans[i] = *st.begin();
                st.erase(st.begin());
            }
        }
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            k |= ans[i];
        } else {
            k &= ans[i];
        }
    }

    cout << k << nl;
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
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
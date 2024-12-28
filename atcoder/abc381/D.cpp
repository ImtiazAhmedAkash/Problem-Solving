/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// 1122 Substring

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

    int ans = 0;
    set<int> st;
    for (int l = 0, r = 0; r + 1 < n; r += 2) {
        if (A[r] != A[r + 1]) {
            l = r + 2;
            st.clear();
        } else {
            while (st.find(A[r]) != st.end()) {
                st.erase(A[l]);
                l += 2;
            }
            st.insert(A[r]);
            ans = max(ans, r - l + 2);
        }
    }

    st.clear();
    for (int l = 1, r = 1; r + 1 < n; r += 2) {
        if (A[r] != A[r + 1]) {
            l = r + 2;
            st.clear();
        } else {
            while (st.find(A[r]) != st.end()) {
                st.erase(A[l]);
                l += 2;
            }
            st.insert(A[r]);
            ans = max(ans, r - l + 2);
        }
    }

    cout << ans << nl;
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
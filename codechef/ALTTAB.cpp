/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ALTTAB - Alt-Tab

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    string ans = "";
    set<string> st;
    for (int i = n - 1; ~i; i--) {
        string s = A[i];
        if (st.find(s) == st.end()) {
            ans += s.substr(s.size() - 2);
            st.insert(s);
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Gap Existence

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    set<int> st(a.begin(), a.end());
    
    string ans = "No";
    for (int i = 0; i < n; i++) {
        if (st.find(a[i] - m) != st.end()) {
            ans = "Yes";
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
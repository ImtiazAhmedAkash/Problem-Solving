/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Trouble Sort

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
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    bool sorted = is_sorted(a.begin(), a.end());
    set<int> st;
    while (n--) {
        int x;
        cin >> x;
        st.insert(x);
    }
    string ans = "YES";
    if (!sorted && st.size() == 1) ans = "NO";
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
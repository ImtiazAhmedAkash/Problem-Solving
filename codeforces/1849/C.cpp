/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Binary String Copying

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
    string s;
    cin >> s;
    s = "+" + s;
    
    vector<int> pref(n + 2);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i] - '0');
    }
    
    vector<int> last_one(n + 2, -1), next_zero(n + 2, n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') last_one[i] = i;
        else last_one[i] = last_one[i - 1];
    }
    for (int i = n; i > 0; i--) {
        if (s[i] == '0') next_zero[i] = i;
        else next_zero[i] = next_zero[i + 1];
    }
    
    auto isSorted = [&] (int l, int r) {
        int ones = pref[r] - pref[l - 1];
        if (ones == 0 || ones == pref[r] - pref[r - ones]) return true;
        return false;
    };
    
    set<pair<int, int>> st;
    while (m--) {
        int l, r;
        cin >> l >> r;
        int left, right;
        if (isSorted(l, r)) {
            left = -1, right = -1;
        } else {
            left = last_one[l - 1] + 1;
            right = next_zero[r + 1] - 1;
        }
        st.insert({left, right});
    }
    cout << st.size() << nl;
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
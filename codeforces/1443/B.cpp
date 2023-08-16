/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Saving the City

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    
    string t = "";
    for (auto &x : s) {
        if ((t.empty() || t.back() == '0') && x == '1') t += '1';
        else if (!t.empty() && x == '0') t += '0';
    }
    while (!t.empty() && t.back() == '0') t.pop_back();
    
    ll ans = 0;
    if (t.size() == 1) ans = a;
    else if (t.size() > 1) {
        int cnt = 0;
        for (int i = 1; i < t.size(); i++) {
            if (t[i] == '0') cnt++;
            else {
                ans += min(cnt * b, a);
                cnt = 0;
            }
            if (i + 1 == t.size()) ans += a;
        }
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
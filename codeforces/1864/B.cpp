/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Swap and Reverse

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ans = s;
    if (k % 2 == 0) {
        sort(ans.begin(), ans.end());
    } else {
        string odd = "", even = "";
        for (int i = 0; i < n; i++) {
            if (i & 1) odd += s[i];
            else even += s[i];
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        for (int i = 0, x = 0, y = 0; i < ans.size(); i++) {
            if (i & 1) ans[i] = odd[x++];
            else ans[i] = even[y++];
        }
    }
    cout << ans << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Blue-Red Permutation

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
    string s;
    cin >> s;
    vector<int> blue, red;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') blue.push_back(a[i]);
        else red.push_back(a[i]);
    }
    sort(blue.begin(), blue.end());
    sort(red.begin(), red.end());
    string ans = "YES";
    int val = 1;
    int indx = 0;
    while (indx < blue.size()) {
        if (blue[indx] >= val) val++;
        indx++;
    }
    indx = 0;
    while (indx < red.size()) {
        if (red[indx] <= val) val++;
        indx++;
    }
    if (val <= n) ans = "NO";
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
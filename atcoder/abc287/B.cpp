/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Postal Card

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string temp = a[i].substr(3);
        for (int j = 0; j < m; j++){
            if (temp == b[j]) {
                ans++;
                break;
            }
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
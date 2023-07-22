/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Word on the Paper

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string ans = "";
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (auto i : s) {
            if (isalpha(i)) ans += i;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
        
    }
    
    return 0;
}
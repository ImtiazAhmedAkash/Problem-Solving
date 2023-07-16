/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Alternately

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
    string s;
    cin >> n >> s;
    
    string ans = "Yes";
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            ans = "No";
            break;
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
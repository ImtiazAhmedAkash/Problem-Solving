/*  In the Name of ALLAH, the most gracious, the most merciful  */

// B - Make Majority

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int one = 0, zero = 0;
    char last = '1';
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            one++;
        } else if (s[i] == '0' && last == '1') {
            zero++;
        }
        last = s[i];
    }
    cout << (zero < one ? "Yes" : "No") << nl;
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
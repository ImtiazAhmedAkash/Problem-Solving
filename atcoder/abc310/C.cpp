/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Reversible

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
    set<string> stick;
    while (n--) {
        string s;
        cin >> s;
        string t = string(s.rbegin(), s.rend());
        if (stick.find(s) == stick.end() && stick.find(t) == stick.end()) stick.insert(s);
    }
    cout << (int) stick.size() << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
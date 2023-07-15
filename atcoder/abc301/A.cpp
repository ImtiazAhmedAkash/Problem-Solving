/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Overall Winner

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
    string s;
    cin >> s;
    int t = count(s.begin(), s.end(), 'T');
    int a = n - t;
    
    string ans = "T";
    if (a > t) ans = "A";
    if (a == t && s.back() == 'T') ans = "A";
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
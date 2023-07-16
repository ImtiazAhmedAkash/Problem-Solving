/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Similar String

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
    string a, b;
    cin >> n >> a >> b;
    
    string ans = "Yes";
    
    replace(a.begin(), a.end(), '1', 'l');
    replace(a.begin(), a.end(), '0', 'o');
    replace(b.begin(), b.end(), '1', 'l');
    replace(b.begin(), b.end(), '0', 'o');
    
    if (a != b) ans = "No";
    
    cout << ans << nl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
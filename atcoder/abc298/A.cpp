/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Job Interview

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s, ans = "No";
    cin >> n >> s;
    
    if (s.find('o') != string::npos && s.find('x') == string::npos) ans = "Yes";
    
    cout << ans << nl;
    
    return 0;
}
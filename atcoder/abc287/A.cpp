/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Majority

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    string str, ans = "Yes";
    while(n--){
        cin >> str;
        if (str == "For") a++;
        else b++;
    }
    if (b > a) ans = "No";
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
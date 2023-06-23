/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Ternary XOR

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * As long as, the two resultant string 'a' and 'b' are the same, 
 * if s[i] = '0', add '0' at the end of 'a' and 'b'.
 * if s[i] = '2', add '1', at the end of 'a' and 'b'.
 * if s[i] = '1', add '1' at the end of 'a' and '0' at the end of 'b'.
 * 
 * Once the third condition is encountered, 'a' becomes greater than 'b'.
 * The problem wants to minimize the greater element. 
 * So, add '0' with 'a' and add s[i] with 'b' until their length becomes n.
 */

void solve() {
    int n;
    string s;
    cin >> n >> s;

    string a = "", b = "";
    for (int i = 0; i < n; i++) {
        if (a > b) {
            a += '0';
            b += s[i];
        } else {
            int x = s[i] - '0';
            if (!x) {
                a += '0';
                b += '0';
            } else {
                a += '1';
                b += ((x - 1) + '0');
            }
        }
    }
    cout << a << nl << b << nl;
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
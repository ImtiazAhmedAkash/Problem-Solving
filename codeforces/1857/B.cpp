/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Maximum Rounding

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    string s;
    cin >> s;
    s = '0' + s;
    int indx = -1;
    for (int i = s.size() - 1; i > 0; i--) {
        if (s[i] >= '5' && s[i] <= '9') {
            if (s[i - 1] != '9') {
                s[i - 1] += 1;
                indx = i;
            }
        }
    }
    for (int i = indx; i < s.size(); i++) s[i] = '0';
    if (s.front() == '0') s.erase(s.begin());
    cout << s << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
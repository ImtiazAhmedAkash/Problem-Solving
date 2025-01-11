/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Binary Path

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
    vector<string> A(2);
    for (auto &x : A) cin >> x;
    A[0] += '2';
    
    int ans = 1;
    string s;
    s += A[0].front();
    for (int i = 0, row = 0; i < n; i++) {
        if (row == 0) {
            char right = A[0][i + 1];
            char down = A[1][i];
            if (right == down) {
                ans++;
                s += right;
            } else if (right < down) {
                ans = 1;
                s += right;
            } else {
                s += down;
                row = 1;
            }
        } else {
            s += A[1][i];
        }
    }
    
    cout << s << nl;
    cout << ans << nl;
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
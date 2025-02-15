/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// B - Geometric Sequence

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    int g = gcd(A[0], A[1]);
    int lob = A[1] / g;
    int hor = A[0] / g;
    
    for (int i = 1; i < n; i++) {
        g = gcd(A[i], A[i - 1]);
        int curLob = A[i] / g;
        int curHor = A[i - 1] / g;
        if (lob != curLob || hor != curHor) {
            cout << "No" << nl;
            return;
        }
    }
    
    cout << "Yes" << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Anonymous Informant

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
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    bool ok = true;
    for (int op = 0, indx = n; op < min(n, k); op++) {
        if (A[indx] > n) {
            ok = false;
            break;
        }
        indx = indx - A[indx];
        if (indx <= 0) indx += n;
    }
    cout << (ok ? "Yes" : "No") << nl;
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
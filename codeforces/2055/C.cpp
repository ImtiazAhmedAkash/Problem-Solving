/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// The Trail

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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector A(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    
    ll target = 0;
    vector<ll> rowSum(n + 1), colSum(m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rowSum[i] += A[i][j];
        }
    }
    
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            colSum[j] += A[i][j];
        }
    }
    target = 0;
    
    int indx = 0;
    int i = 0, j = 0;
    while (indx < s.size()) {
        if (s[indx] == 'R') {
            A[i][j] = target - colSum[j];
            rowSum[i] += A[i][j];
            colSum[j] += A[i][j];
            j++;
        } else {
            A[i][j] = target - rowSum[i];
            rowSum[i] += A[i][j];
            colSum[j] += A[i][j];
            i++;
        }
        indx++;
    }
    
    A[i][j] = target - colSum[j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << nl;
    }
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
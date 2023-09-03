/*  In the Name of ALLAH, the most gracious, the most merciful  */

// No Prime Differences

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    int cur = 1;
    if (!isPrime(n)) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                a[i][j] = cur++;
            }
        }
    } else if (!isPrime(m)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = cur++;
            }
        }
    } else {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                a[i][j] = cur++;
            }
            if (cur > m * n) cur = n + 1;
            else cur += n;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
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
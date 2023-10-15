/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Inna and New Matrix of Candies

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
    map<int, int> M;
    while (n--) {
        string s;
        cin >> s;
        int d = s.find('G');
        int c = s.find('S');
        if (c < d) {
            cout << -1 << nl;
            return;
        }
        M[c - d]++;
    }
    cout << M.size() << nl;
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
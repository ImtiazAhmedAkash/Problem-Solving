/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Word Game

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
    vector A(3, vector<string>());
    map<string, int> M;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            A[i].push_back(s);
            M[s]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        int ans = 0;
        for (auto x : A[i]) {
            if (M[x] == 1) ans += 3;
            else if (M[x] == 2) ans += 1;
        }
        cout << ans << " ";
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
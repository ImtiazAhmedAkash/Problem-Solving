/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Card Game for Three (ABC Edit)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    vector<queue<char>> a(3);
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        for (auto x : s) {
            a[i].push(x);
        }
    }
    char x = a[0].front();
    a[0].pop();
    while (!a[x - 'a'].empty()) {
        char y = a[x - 'a'].front();
        a[x - 'a'].pop();
        x = y;
    }
    cout << (char)toupper(x) << nl;
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
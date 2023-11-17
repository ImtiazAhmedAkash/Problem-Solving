/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sum of Two Values

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, x;
    cin >> n >> x;
    map<int, vector<int>> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]].push_back(i + 1);
    }
    for (int i = 0; i < n - 1; i++) {
        if (x == 2 * v[i] && m[v[i]].size() > 1) {
            cout << m[v[i]][0] << " " << m[v[i]][1];
            return;
        } else if (m.find(x - v[i]) != m.end() && (x - v[i] != v[i])) {
            cout << i + 1 << " " << m[x - v[i]].front();
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
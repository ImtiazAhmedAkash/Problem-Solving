/*  In the name of ALLAH, the most gracious, the most merciful  */

// Number Replacement

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * Iterate a loop. 
 * In every i-th iteration, map v[i] with str[i] if v[i] is not mapped (not found in the map).
 * If v[i] is already mapped but with different character, the answer is "NO".
 * Otherwise, the answer is "YES".
 * Print the answer.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    string str, ans = "YES";
    cin >> str;
    map<int, char> m;
    for (int i = 0; i < n; i++) {
        if (m.find(v[i]) == m.end()) {
            m[v[i]] = str[i];
        } else if (m[v[i]] != str[i]) {
            ans = "NO";
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
/*  In the name of ALLAH, the most gracious, the most merciful  */

// Maxmina

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * If any element is 1, the answer is "YES".
 * Otherwise, the answer is "NO". Print the answer.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        string ans = "NO";

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == 1) ans = "YES";
        }
        cout << ans << '\n';
    }

    return 0;
}
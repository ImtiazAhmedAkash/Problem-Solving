/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Unnatural Language Processing

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
    string s;
    cin >> s;

    auto isVowel = [&](char c) -> bool {
        return c == 'a' || c == 'e';
    };

    string ans = "";
    while (!s.empty()) {
        int x = 0;
        if (isVowel(s.back())) {
            x = 2;
        } else {
            x = 3;
        }
        while (x--) {
            ans += s.back();
            s.pop_back();
        }
        if (!s.empty()) ans += '.';
    }
    reverse(ans.begin(), ans.end());
    cout << ans << nl;
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
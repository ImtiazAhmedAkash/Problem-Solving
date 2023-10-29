/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Qingshan Loves Strings 2

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
    
    if (count(s.begin(), s.end(), '0') != count(s.begin(), s.end(), '1')) {
        cout << -1 << nl;
        return;
    }

    vector<int> ans;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (s[i] != s[j]) {
            s.pop_back();
            i++, j--;
        } else if (s[i] == '0') {
            ans.push_back(j + 1);
            s += "01";
            j += 2;
        } else if (s[i] == '1') {
            s.insert(s.begin() + i, '1');
            s.insert(s.begin() + i, '0');
            ans.push_back(i);
            j += 2;
        }
    }
    cout << ans.size() << nl;
    for (auto x : ans) cout << x << " ";
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
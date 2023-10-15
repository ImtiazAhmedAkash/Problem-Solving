/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Set of Strings

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
    vector<int> cnt(26);
    for (auto x : s) {
        cnt[x - 'a'] = 1;
    }
    int distinct = count(cnt.begin(), cnt.end(), 1);
    if (distinct < n) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    int cur = 1;
    cout << s.front();
    cnt[s[0] - 'a']--;
    for (int i = 1; i < s.size(); i++) {
        if (cur != n && cnt[s[i] - 'a']) {
            cur++, cnt[s[i] - 'a']--;
            cout << nl;
        }
        cout << s[i];
    }
    cout << nl;
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
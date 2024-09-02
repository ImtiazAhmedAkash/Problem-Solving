/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sakurako's Hobby

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    string s;
    cin >> s;
    s = '-' + s;

    vector<int> ans(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (ans[i] != -1) continue;
        set<int> used;
        int cur = i;
        int cnt = 0;
        while (used.find(cur) == used.end()) {
            used.insert(cur);
            cur = A[cur];
            if (s[cur] == '0') cnt++;
        }
        while (!used.empty()) {
            ans[*used.begin()] = cnt;
            used.erase(used.begin());
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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
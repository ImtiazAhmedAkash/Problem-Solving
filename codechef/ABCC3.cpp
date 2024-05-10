/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ABCC3 - ABC Conjecture 3

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
    vector<deque<int>> pos(3);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    vector<int> prev_b(n);
    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') cur = i;
        if (s[i] == 'c') prev_b[i] = cur;
    }

    vector<int> next_b(n);
    cur = n;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'b') cur = i;
        if (s[i] == 'a') next_b[i] = cur;
    }

    int ans = 0;
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && s[i] != 'a') i++;
        while (i < j && s[j] != 'c') j--;
        if (s[i] != 'a' || s[j] != 'c') break;

        int a = lower_bound(pos[2].begin(), pos[2].end(), next_b[i]) - pos[2].begin();
        a = (int)pos[2].size() - a;
        int c = upper_bound(pos[0].begin(), pos[0].end(), prev_b[j]) - pos[0].begin();

        if (a + c == 0) {
            i++, j--;
            continue;
        }

        if (a <= c) {
            pos[2].pop_back();
            j--;
        } else {
            pos[0].pop_front();
            i++;
        }
        ans++;
    }

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
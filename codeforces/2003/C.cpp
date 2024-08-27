/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Turtle and Good Pairs

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
    for (auto &c : s) {
        cnt[c - 'a']++;
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            pq.push({cnt[i], i});
        }
    }

    string ans;
    while (pq.size() >= 2) {
        auto x = pq.top();
        pq.pop();
        auto y = pq.top();
        pq.pop();

        for (int i = 0; i < y.first; i++) {
            ans += 'a' + x.second;
            ans += 'a' + y.second;
        }

        x.first -= y.first;
        if (x.first) {
            pq.push(x);
        }
    }

    if (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        for (int i = 0; i < x.first; i++) {
            ans += 'a' + x.second;
        }
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
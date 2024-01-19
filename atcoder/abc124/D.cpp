/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Handstand

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = '!' + s;
    vector<int> starts(n + 2), ends(n + 2);
    vector<pair<int, int>> zero;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        if (s[j] == '0') {
            int cnt = 0;
            while (j <= n && s[j] == '0') {
                cnt++, j++;
            }
            zero.push_back({cnt, j - 1});
        } else {
            int cnt = 0;
            while (j <= n && s[j] == '1') {
                cnt++, j++;
            }
            starts[i] = ends[j - 1] = cnt;
            ans = max(ans, cnt);
        }
        i = j - 1;
    }

    int cur = zero.empty() ? 0 : ends[zero.front().second - zero.front().first];
    for (int i = 0; i < min((int)zero.size(), k); i++) {
        cur += zero[i].first + starts[zero[i].second + 1];
    }
    ans = max(ans, cur);

    for (int i = k; i < zero.size(); i++) {
        cur -= (zero[i - k].first + ends[zero[i - k].second - zero[i - k].first]);
        cur += zero[i].first + starts[zero[i].second + 1];
        ans = max(ans, cur);
    }
    cout << ans << nl;
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
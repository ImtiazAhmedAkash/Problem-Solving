/*  In the Name of ALLAH, the most gracious, the most merciful  */

// E - Novice's Mistake

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 10000;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;

    int len = 1 + log10(n);
    int mul = 1;
    for (int i = 1; i <= len; i++) {
        mul *= 10;
    }
    
    for (int a = 1; a <= N; a++) {
        int total = a * n;
        ll cur = 0;
        for (int i = 1; i <= a && cur <= total; i++) {
            cur *= mul;
            cur += n;
        }
        
        int total_len = a * len;
        int cur_len = 1 + log10(cur);
        while (cur) {
            int b = total_len - cur_len;
            if (0 < b && b <= min(total, N) && total - cur == b) {
                ans.push_back({a, b});
            }
            cur /= 10;
            cur_len--;
        }
    }

    cout << ans.size() << nl;
    for (auto [a, b] : ans) {
        cout << a << " " << b << nl;
    }
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Yet Another Array Restoration

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    set<int> ans = {x, y};
    int diff = y - x;
    vector<int> divisor {1, diff};
    for (int i = 2; i * i <= diff; i++) {
        if (diff % i == 0) {
            divisor.push_back(i);
            if (i != (diff / i)) divisor.push_back(diff / i);
        }
    }
    sort(divisor.begin(), divisor.end());
    int dist;
    for (int i = 0; i < divisor.size(); i++) {
        int total = (diff / divisor[i]) + 1;
        if (total <= n) {
            dist = divisor[i];
            break;
        }
    }
    int val = y;
    while (ans.size() != n && val > 0) {
        ans.insert(val);
        val -= dist;
    }
    while (ans.size() != n) {
        ans.insert(y);
        y += dist;
    }
    for (auto x : ans) cout << x << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
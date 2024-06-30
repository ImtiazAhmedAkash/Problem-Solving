/*  In the Name of ALLAH, the most gracious, the most merciful  */

// AtCoder Magics

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void solve() {
    int n;
    cin >> n;
    vector<int> power(n);
    set<int> st;
    vector<pair<int, int>> cost(n);
    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        st.insert(a);
        power[i] = a;
        cost[i] = {c, i};
    }
    sort(cost.begin(), cost.end(), greater());

    vector<int> ans;
    for (auto [x, y] : cost) {
        if (power[y] == *st.rbegin()) {
            ans.push_back(y + 1);
        }
        st.erase(power[y]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
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
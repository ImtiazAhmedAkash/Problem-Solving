/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Prepare Another Box

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
    vector<int> toy(n);
    for (auto &x : toy) cin >> x;

    vector<int> box(n - 1);
    for (auto &x : box) cin >> x;

    sort(toy.begin(), toy.end());
    sort(box.begin(), box.end());

    int bad = 0, ans = toy.front();
    int l = n - 1, r = n - 2;
    while (l >= 0 && r >= 0) {
        if (toy[l] <= box[r]) {
            l--, r--;
        } else {
            bad++;
            ans = max(ans, toy[l]);
            l--;
        }
        if (bad == 2) {
            cout << -1 << nl;
            return;
        }
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
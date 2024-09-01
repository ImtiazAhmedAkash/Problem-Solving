/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Piano 3

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
    vector<int> left, right;
    for (int i = 0; i < n; i++) {
        int x;
        char y;
        cin >> x >> y;
        if (y == 'L') {
            left.push_back(x);
        } else {
            right.push_back(x);
        }
    }

    int ansLeft = inf, ansRight = inf;
    for (int i = 1; i <= 100; i++) {
        int curLeft = 0, curRight = 0;
        int cur = i;
        for (auto x : left) {
            curLeft += abs(cur - x);
            cur = x;
        }
        cur = i;
        for (auto x : right) {
            curRight += abs(cur - x);
            cur = x;
        }
        ansLeft = min(ansLeft, curLeft);
        ansRight = min(ansRight, curRight);
    }

    cout << ansLeft + ansRight << nl;
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
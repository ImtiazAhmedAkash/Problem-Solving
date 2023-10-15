/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Canvas Frames

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
    vector<int> cnt(101);
    while (n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for (int i = 1; i < 101; i++) {
        ans += cnt[i] / 2;
    }
    cout << (ans >> 1) << nl;
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
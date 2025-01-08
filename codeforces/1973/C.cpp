/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Cat, Fox and Double Maximum

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
    
    // for even indices
    vector<pair<int, int>> good, bad;
    for (int i = 2; i < n; i += 2) {
        good.push_back({A[i], i});
    }
    bad.push_back({A[1], 1});
    bad.push_back({A[n], n});
    for (int i = 3; i < n; i += 2) {
        bad.push_back({A[i], i});
    }
    
    sort(good.begin(), good.end());
    sort(bad.begin(), bad.end());
    
    vector<int> ans(n + 1);
    
    auto check = [&]() -> bool {
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            int a = A[i - 1] + ans[i - 1];
            int b = A[i] + ans[i];
            int c = A[i + 1] + ans[i + 1];
            if (a < b && b > c) cnt++;
        }
        return cnt == (n - 2) / 2;
    };
    
    int val = n;
    for (auto &[a, b] : good) {
        ans[b] = val--;
    }
    for (auto &[a, b] : bad) {
        ans[b] = val--;
    }
    
    if (check()) {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " \n"[i == n];
        }
        return;
    }
    
    // for odd indices
    good.clear();
    bad.clear();
    
    for (int i = 3; i < n; i += 2) {
        good.push_back({A[i], i});
    }
    bad.push_back({A[1], 1});
    bad.push_back({A[n], n});
    for (int i = 2; i < n; i += 2) {
        bad.push_back({A[i], i});
    }
    
    sort(good.begin(), good.end());
    sort(bad.begin(), bad.end());
    
    val = n;
    for (auto &[a, b] : good) {
        ans[b] = val--;
    }
    for (auto &[a, b] : bad) {
        ans[b] = val--;
    }
    
    if (check()) {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " \n"[i == n];
        }
        return;
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
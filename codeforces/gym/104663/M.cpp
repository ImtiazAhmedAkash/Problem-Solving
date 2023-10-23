/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Banana Monitor

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
    int n, nmx, a, c;
    cin >> n >> nmx >> a >> c;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    int ans = 0;
    bool alarm = false;
    for (int i = 0; i < n;) {
        if (not alarm) {
            if (A[i] <= nmx) {
                i++;
                continue;
            }
            int cnt = 0;
            while (i < n && cnt < a && A[i] > nmx) {
                cnt++, i++;
            }
            if (cnt == a) {
                alarm = true;
                ans++;
                continue;
            }
        } else {
            if (A[i] > nmx) {
                ans++;
                i++;
                continue;
            }
            int cnt = 0;
            while(i < n && cnt < c && A[i] <= nmx) {
                cnt++, i++, ans++;
            }
            if (cnt == c) {
                alarm = false;
                ans--;
                continue;
            }
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
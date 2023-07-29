/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cutting Out

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 200005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(N + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    auto check = [&] (int mid) {
        int total_len = 0;
        for (auto i : cnt) {
            total_len += (i / mid);
        }
        return total_len < k;
    };
    
    int L = 1, R = 2e5;
    while (L < R) {
        int M = L + (R - L + 1) / 2;
        if (check(M)) R = M - 1;
        else L = M;
    }
    
    int max_count = R;
    int cnt_ans = 0;
    for (int i = 1; i < cnt.size(); i++) {
        for (int j = 0; j < (cnt[i] / max_count); j++) {
            cout << i << " ";
            if (++cnt_ans == k) return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}
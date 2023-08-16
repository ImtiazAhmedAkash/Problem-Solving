/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dual (Hard Version)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int pos = 0, neg = 0;
    for (auto &x : a) {
        cin >> x;
        if (x > 0) pos++;
        else if (x < 0) neg++;
    }
    
    if (is_sorted(a.begin(), a.end())) {
        cout << 0 << nl;
        return;
    }
    
    int max_indx = max_element(a.begin(), a.end()) - a.begin();
    int min_indx = min_element(a.begin(), a.end()) - a.begin();
    int mini = a[min_indx];
    int maxi = a[max_indx];
    
    bool make_neg = false, make_pos = false;
    if (pos && neg) {
        if (maxi < abs(mini)) {
            if (neg >= 8) make_neg = true;
            else make_pos = true;
        } else {
            if (pos >= 8) make_pos = true;
            else make_neg = true;
        }
    }
    
    vector<pair<int, int>> ans;
    if (make_neg) {
        while (abs(mini) < maxi) {
            mini += mini;
            a[min_indx] = mini;
            ans.push_back({min_indx + 1, min_indx + 1});
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                a[i] += mini;
                ans.push_back({i + 1, min_indx + 1});
            }
        }
        pos = 0;
    } else if (make_pos) {
        while (abs(mini) > maxi) {
            maxi += maxi;
            a[max_indx] = maxi;
            ans.push_back({max_indx + 1, max_indx + 1});
        }
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                a[i] += maxi;
                ans.push_back({i + 1, max_indx + 1});
            }
        }
        neg = 0;
    }
    
    if (neg == 0) {
        for (int i = 2; i <= n; i++) {
            ans.push_back({i, i - 1});
        }
    } else if (pos == 0) {
        for (int i = n - 1; i >= 1; i--) {
            ans.push_back({i, i + 1});
        }
    }
    
    cout << ans.size() << nl;
    for (auto it: ans) cout << it.first << " " << it.second << nl;
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
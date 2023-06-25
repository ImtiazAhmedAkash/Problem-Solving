/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Nastia and a Good Array

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Find the minimum element of the array.
 * Change all the elements to the left and right of the mininum element by minimum element + (1, 2, 3, ...).
 * In this way, all the adjacent elements will have gcd 1, and the minimum element will not be changed.
 * 
 * For example, If an array is 5 2 1 4 6 
 * After performing the aforementioned operation,
 * The final array will be 3 2 1 2 3
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mini = INF, indx = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < mini) {
            mini = a[i];
            indx = i;
        }
    }

    vector<pair<int, int>> ans, res;
    int val = mini + 1;
    for (int i = indx + 1; i < n; i++) {
        res.push_back({indx + 1, i + 1});
        ans.push_back({mini, val++});
    }

    val = mini + 1;
    for (int i = indx - 1; i >= 0; i--) {
        res.push_back({indx + 1, i + 1});
        ans.push_back({mini, val++});
    }

    cout << ans.size() << nl;
    for (int i = 0; i < ans.size(); i++) {
        cout << res[i].first << " " << res[i].second << " " << ans[i].first << " " << ans[i].second << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
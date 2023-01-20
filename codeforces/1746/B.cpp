/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rebellion

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

/*
 * The task is to make the array non-decreasing.
 * Take two pointers left and right. 
 * left points to the 0-th index and right pointes to the (n - 1)-th index.
 * If v[left] is equal to 0, increment it by 1.
 * If the v[right] is equal to 1, decrement it by 1.
 * If v[left] is 1 and v[right] is 0, left++ and right--.
 * Because v[left] can be added to the v[right]. And then v[left] is removed.
 * As v[left] is removed, left is incremented by 1 and 
 * as v[right] becomes 1, right is decremented by 1.
 * Repeat this as long as left is less than right.
 * Print the value of ans.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    int ans = 0, left = 0, right = n - 1;
    while (left < right) {
        if (v[left] == 0) left++;
        if (v[right] == 1)
            right--;
        else if (v[left] == 1 && v[right] == 0) {
            left++;
            right--;
            ans++;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }

    return 0;
}
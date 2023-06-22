/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Make It Good

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Use binary search from 0 to n - 1.
 * If the elements from mid to n - 1 form a good array, the answer is on the left.
 * Otherwise, the answer is on the right.
 * 
 * In the check function, create the array 'c' described in the problem.
 * If c is sorted, return true. Otherwise, return false.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    auto check = [&](int mid) {
        vector<int> c;
        int l = mid, r = n - 1;
        while (l <= r) {
            if (a[l] <= a[r]) {
                c.push_back(a[l]);
                l++;
            } else {
                c.push_back(a[r]);
                r--;
            }
        }
        if (is_sorted(c.begin(), c.end())) return true;
        return false;
    };

    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    
    cout << lo << nl;
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
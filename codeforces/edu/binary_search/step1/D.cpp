/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Fast Search

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
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (a[mid] >= l) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        int start = lo;
        lo = 0, hi = n;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if (a[mid] > r) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        int end = lo;
        cout << end - start << " ";
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
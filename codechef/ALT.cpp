/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ALT - Alter Ego

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
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x & 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }
    int sz = odd.size();
    if (sz & 1) {
        cout << -1 << nl;
        return;
    }

    vector<int> ans(n);
    int indx = 0;
    auto fun = [&](vector<int> A) {
        sort(A.begin(), A.end(), greater<int>());
        for (int i = 0, j = ((int)A.size()) / 2; j < A.size(); i++, j++) {
            int x = (A[i] + A[j]) / 2;
            int y = (A[i] - A[j]) / 2;
            ans[indx] = x;
            ans[indx + n / 2] = y;
            indx++;
        }
    };

    fun(odd);
    fun(even);

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << nl;
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
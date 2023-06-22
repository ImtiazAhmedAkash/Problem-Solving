/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Districts Connection

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Edges between same elements cannot be created.
 * Take two vectors. Put elements (that are same as the first element) in a vector ("same").
 * And the rest of them in another ("diff").
 * 
 * If all the elements are the same, the answer is "NO".
 * Otherwise, the answer is "YES".
 * 
 * For all elements (except for one) in the vector "same", add an edge with any element of the "diff" vector.
 * In this case, the last element of the vector "diff" was chosen.
 * 
 * Then, For all elements in the vector "diff", add an edge with that one element of vector "same" that was left
 * in the previous operation.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    vector<int> same, diff;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[0]) same.push_back(i + 1);
        else diff.push_back(i + 1);
    }

    if (diff.empty()) {
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl;
    while (!diff.empty()) {
        cout << same.back() << " " << diff.back() << nl;
        if (same.size() > 1)
            same.pop_back();
        else
            diff.pop_back();
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
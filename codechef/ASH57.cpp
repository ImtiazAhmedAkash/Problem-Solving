/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ASH57 - Chroma Swap

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
    vector<int> A(n), CA(n), B(n);
    set<int> CB;
    vector<multiset<int>> S(2 * n + 1);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) {
        cin >> CA[i];
        S[CA[i]].insert(A[i]);
    }
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        CB.insert(x);
        S[x].insert(B[i]);
    }

    int lst = 0;
    for (int i = 0; i < n; i++) {
        int color = CA[i];
        if (CB.find(color) != CB.end()) {
            auto it = S[color].lower_bound(lst);
            if (it == S[color].end()) it--;
            A[i] = *it;
            S[color].erase(it);
        }
        lst = A[i];
    }
    cout << (is_sorted(A.begin(), A.end()) ? "Yes" : "No") << nl;
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
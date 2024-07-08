/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Swap Dilemma

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    vector<int> B(n);
    for (auto &x : B) cin >> x;

    auto sA = A;
    auto sB = B;
    sort(sA.begin(), sA.end());
    sort(sB.begin(), sB.end());

    if (sA != sB) {
        cout << "NO" << nl;
        return;
    }

    ordered_set<int> os;
    ll inv_A = 0;
    for (int i = 0; i < n; i++) {
        inv_A += os.order_of_key(A[i]);
        os.insert(A[i]);
    }
    os.clear();

    ll inv_B = 0;
    for (int i = 0; i < n; i++) {
        inv_B += os.order_of_key(B[i]);
        os.insert(B[i]);
    }

    cout << (inv_A % 2 == inv_B % 2 ? "YES" : "NO") << nl;
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
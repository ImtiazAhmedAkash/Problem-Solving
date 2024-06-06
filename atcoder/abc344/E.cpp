/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Insert or Erase

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e15;
const int mod = 998244353;
const int N = 2e5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    map<int, int> Prev, Next;
    for (int i = 0; i < n; i++) {
        Prev[A[i]] = (i == 0) ? -1 : A[i - 1];
        Next[A[i]] = (i + 1 == n) ? -1 : A[i + 1];
    }
    int start = A[0];

    int q;
    cin >> q;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            int y;
            cin >> y;
            Prev[Next[x]] = y;
            Next[y] = Next[x];
            Next[x] = y;
            Prev[y] = x;
        } else {
            if (x == start) {
                start = Next[start];
            }
            Next[Prev[x]] = Next[x];
            Prev[Next[x]] = Prev[x];
            Next.erase(x);
            Prev.erase(x);
        }
    }
    while (start != -1) {
        cout << start << ' ';
        start = Next[start];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Physical Education Lesson

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
    int n, x;
    cin >> n >> x;

    auto find_divisor = [&](int m) -> vector<int> {
        vector<int> D;
        for (int i = 1; i * i <= m; i++) {
            if (m % i) continue;
            if (i % 2 == 0) {
                D.push_back((i + 2) / 2);
            }
            int j = m / i;
            if (j % 2 == 0) {
                D.push_back((j + 2) / 2);
            }
        }
        return D;
    };

    set<int> st;
    for (auto d : find_divisor(n - x)) {
        if (x <= d) {
            st.insert(d);
        }
    }

    for (auto d : find_divisor(n + x - 2)) {
        if (x <= d) {
            st.insert(d);
        }
    }

    cout << st.size() << nl;
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
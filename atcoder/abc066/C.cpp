/*  In the Name of ALLAH, the most gracious, the most merciful  */

// pushpush

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
    int rev = 0;
    deque<int> D;
    while (n--) {
        int x;
        cin >> x;
        rev ? D.push_front(x) : D.push_back(x);
        rev = !rev;
    }
    if (rev) {
        while (!D.empty()) {
            cout << D.back() << " ";
            D.pop_back();
        }
    } else {
        while (!D.empty()) {
            cout << D.front() << " ";
            D.pop_front();
        }
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
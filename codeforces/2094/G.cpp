/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// G - Chimpanzini Bananini

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int q;
    cin >> q;
    
    deque<int> dq;
    ll totalSum = 0;
    ll forwardSum = 0, reverseSum = 0;
    int reversed = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            if (reversed) {
                forwardSum += totalSum;
                forwardSum -= dq.size() * dq.front();
                reverseSum -= totalSum;
                reverseSum += dq.size() * dq.front();
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else {
                forwardSum += totalSum;
                forwardSum -= dq.size() * dq.back();
                reverseSum -= totalSum;
                reverseSum += dq.size() * dq.back();
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else if (op == 2) {
            reversed ^= 1;
            swap(forwardSum, reverseSum);
        }
        else {
            int x;
            cin >> x;
            if (reversed) {
                dq.push_front(x);
            }
            else {
                dq.push_back(x);
            }
            forwardSum += dq.size() * x;
            reverseSum += totalSum + x;
            totalSum += x;
        }
        
        cout << forwardSum << nl;
    }
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
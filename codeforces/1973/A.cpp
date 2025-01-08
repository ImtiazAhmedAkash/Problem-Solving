/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Chess For Three

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
    priority_queue<int> pq;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        if (x) {
            pq.push(x);
        }
    }
    
    int ans = 0;
    while (pq.size() > 1) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        ans++;
        
        if (x - 1 > 0) {
            pq.push(x - 1);
        }
        if (y - 1 > 0) {
            pq.push(y - 1);
        }
    }
    
    cout << (pq.empty() || pq.top() % 2 == 0 ? ans : -1) << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// LR insertion

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
    string s;
    cin >> s;
    queue<int> Q;
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if(s[i] == 'L') stk.push(i);
        else Q.push(i);
    }
    stk.push(n);
    while (!Q.empty()) {
        cout << Q.front() << ' ';
        Q.pop();
    }
    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
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
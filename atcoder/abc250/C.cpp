/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Adjacent Swaps

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
    int n, q;
    cin >> n >> q;
    vector<int> box(n + 1), ball(n + 1);
    iota(box.begin(), box.end(), 0);
    iota(ball.begin(), ball.end(), 0);
    while (q--) {
        int x;
        cin >> x;
        if (ball[x] == n) {
            int y = box[n - 1];
            swap(box[n - 1], box[n]);
            swap(ball[x], ball[y]);
        } else {
            int indx = ball[x] + 1;
            int y = box[indx];
            swap(box[ball[x]], box[indx]);
            swap(ball[x], ball[y]);
        }
    }
    for (int i = 1; i <= n; i++) cout << box[i] << " ";
    cout << nl;
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
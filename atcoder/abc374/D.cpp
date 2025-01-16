/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Laser Marking

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 9e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, s, t;
    cin >> n >> s >> t;
    vector<array<int, 4>> A(n);
    for (auto &[a, b, c, d] : A) cin >> a >> b >> c >> d;
    
    auto distance = [&](int x1, int y1, int x2, int y2) -> double {
        int x = x1 - x2;
        int y = y1 - y2;
        return sqrtl(x * x + y * y);
    };
    
    double ans = INF;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    do {
        
        auto fun = [&](auto&& self, int indx, int curx, int cury, double cur) -> void {
            if (indx == n) {
                ans = min(ans, cur);
                return;
            }
            
            auto [a, b, c, d] = A[order[indx]];
            double left = 0;
            left += distance(curx, cury, a, b) / s;
            left += distance(a, b, c, d) / t;
            self(self, indx + 1, c, d, cur + left);
            
            double right = 0;
            right += distance(curx, cury, c, d) / s;
            right += distance(a, b, c, d) / t;
            self(self, indx + 1, a, b, cur + right);
        };
        
        fun(fun, 0, 0, 0, 0);
        
    } while (next_permutation(order.begin(), order.end()));
    
    cout << fixed << setprecision(10);
    cout << ans << nl;
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
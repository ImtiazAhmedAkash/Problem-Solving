/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vlad and a Sum of Sum of Digits

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5;

vector<int> ans(N + 5);

void precalculate() {
    auto digitSum = [&](int x) -> int {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };
    
    for (int i = 1; i <= N; i++) {
        ans[i] = ans[i - 1] + digitSum(i);
    }
}

void solve() {
    int n;
    cin >> n;
    cout << ans[n] << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precalculate();
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dima and Lisa

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 1e5 + 5;

bool isPrime (int x) {
    if (x == 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    if (isPrime(n)) {
        cout << 1 << nl << n << nl;
        return;
    }
    
    vector<int> ans;
    for (int m = n - 2; m > 1; m -= 2) {
        if (isPrime(m)) {
            ans.push_back(m);
            n -= m;
            break;
        }
    }
    
    if (isPrime(n)) {
        ans.push_back(n);
    } else {
        for (int i = 2; i < n; i++) {
            if (isPrime(i) && isPrime(n - i)) {
                ans.push_back(i);
                ans.push_back(n - i);
                break;
            }
        }
    }
    
    cout << ans.size() << nl;
    for (auto x : ans) cout << x << " ";
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
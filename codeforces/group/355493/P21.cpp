/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Prime Sieve

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

vector<int> prime;
void sieve(int n) {
    vector<bool> vis(n + 1, true);
    for (int i = 2; i <= n; i++) {
        if (vis[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= n; j += i) vis[j] = false;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    sieve(n);
    cout << prime.size() << nl;
    for (auto &x : prime) cout << x << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
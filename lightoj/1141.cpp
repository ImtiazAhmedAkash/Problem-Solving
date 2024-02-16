/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1141 - Number Transformation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1000;

vector<bool> isPrime(N + 5, true);
vector PF(N + 1, vector<int>());

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i + i; j <= N; j += i) {
                isPrime[j] = false;
                PF[j].push_back(i);
            }
        }
    }
}

void solve() {
    int s, t;
    cin >> s >> t;

    auto bfs = [&](int src) -> int {
        vector<int> move(t + 1, inf);
        queue<int> Q;
        Q.push(src);
        move[src] = 0;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto w : PF[u]) {
                int v = u + w;
                if (v <= t && move[u] + 1 < move[v]) {
                    move[v] = move[u] + 1;
                    Q.push(v);
                }
            }
            if (move[t] != inf) return move[t];
        }
        return -1;
    };

    cout << bfs(s) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}
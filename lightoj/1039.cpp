/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1039 - A Toy Company

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
    string s, t;
    cin >> s >> t;
    map<string, int> moves;
    set<string> banned;
    int n;
    cin >> n;
    while (n--) {
        string a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                for (int k = 0; k < c.size(); k++) {
                    string x = "";
                    x += a[i];
                    x += b[j];
                    x += c[k];
                    banned.insert(x);
                }
            }
        }
    }

    if (banned.find(s) != banned.end() || banned.find(t) != banned.end()) {
        cout << -1 << nl;
        return;
    }

    auto bfs = [&](string s) -> int {
        queue<string> Q;
        Q.push(s);
        moves[s] = 0;
        while (!Q.empty()) {
            string u = Q.front();
            Q.pop();

            if (u == t) {
                return moves[u];
            }

            for (int i = 0; i < u.size(); i++) {
                string x = u;
                if (x[i] == 'z') {
                    x[i] = 'a';
                } else {
                    x[i]++;
                }
                if (banned.find(x) == banned.end() && (moves.find(x) == moves.end() || moves[u] + 1 < moves[x])) {
                    Q.push(x);
                    moves[x] = moves[u] + 1;
                }

                x = u;
                if (x[i] == 'a') {
                    x[i] = 'z';
                } else {
                    x[i]--;
                }
                if (banned.find(x) == banned.end() && (moves.find(x) == moves.end() || moves[u] + 1 < moves[x])) {
                    Q.push(x);
                    moves[x] = moves[u] + 1;
                }
            }
        }
        return -1;
    };

    cout << bfs(s) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}
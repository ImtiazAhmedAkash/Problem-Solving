/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 11488 - Hyper Prefix Sets

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct Node {
    int cnt;
    int next[2];
    Node() {
        cnt = 0;
        memset(next, -1, sizeof next);
    }
};

struct Trie {
    int nodeCount;
    vector<Node> nodes;
    Trie() {
        nodeCount = 1;
        nodes.resize(1);
    }
    int query(const string& s) {
        int cur = 0;
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int indx = s[i] - '0';
            if (nodes[cur].next[indx] == -1) {
                nodes.push_back(Node());
                nodes[cur].next[indx] = nodeCount++;
            }
            cur = nodes[cur].next[indx];
            nodes[cur].cnt++;
            ans = max(ans, (i + 1) * nodes[cur].cnt);
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    Trie trie;

    while (n--) {
        string s;
        cin >> s;
        ans = max(ans, trie.query(s));
    }
    cout << ans << nl;
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

// NPLFLF - Query On Strings

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

struct Node {
    int cnt;
    int next[26];
    Node() {
        cnt = 0;
        memset(next, -1, sizeof next);
    }
};

struct Trie {
    vector<Node> nodes;
    vector<multiset<int>> depth;
    int nodeCount;
    Trie() {
        nodeCount = 1;
        nodes.resize(1);
        depth.resize(N + 5);
    }
    void insert(const string& s) {
        int cur = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int indx = s[i] - 'a';
            if (nodes[cur].next[indx] == -1) {
                nodes[cur].next[indx] = nodeCount++;
                nodes.push_back(Node());
            }
            cur = nodes[cur].next[indx];
            if (nodes[cur].cnt) {
                depth[i + 1].erase(depth[i + 1].find(nodes[cur].cnt));
            }
            nodes[cur].cnt++;
            depth[i + 1].insert(nodes[cur].cnt);
        }
    }
    int query(int k, int l) {
        return !depth[l].empty() && *depth[l].rbegin() >= k;
    }
    void remove(const string& s) {
        int cur = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int indx = s[i] - 'a';
            cur = nodes[cur].next[indx];
            depth[i + 1].erase(depth[i + 1].find(nodes[cur].cnt));
            nodes[cur].cnt--;
            if (nodes[cur].cnt) {
                depth[i + 1].insert(nodes[cur].cnt);
            }
        }
    }
};

void solve() {
    int q;
    cin >> q;
    vector<string> A(q + 1);
    Trie trie;
    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            A[i] = s;
            trie.insert(s);
        } else if (op == 2) {
            int k, l;
            cin >> k >> l;
            cout << (trie.query(k, l) ? "YES" : "NO") << nl;
        } else {
            int x;
            cin >> x;
            trie.remove(A[x]);
            A[x] = "";
        }
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
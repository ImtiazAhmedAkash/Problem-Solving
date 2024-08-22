/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vasiliy's Multiset

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 32;

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
    void insert(const int x) {
        int cur = 0;
        for (int bit = N - 1; bit >= 0; bit--) {
            int indx = (x >> bit) & 1;
            if (nodes[cur].next[indx] == -1) {
                nodes.push_back(Node());
                nodes[cur].next[indx] = nodeCount++;
            }
            cur = nodes[cur].next[indx];
            nodes[cur].cnt++;
        }
    }
    void remove(const int x) {
        int cur = 0;
        for (int bit = N - 1; bit >= 0; bit--) {
            int indx = (x >> bit) & 1;
            cur = nodes[cur].next[indx];
            nodes[cur].cnt--;
        }
    }
    int query(const int x) {
        int cur = 0;
        int ans = 0;
        for (int bit = N - 1; bit >= 0; bit--) {
            int indx = (x >> bit) & 1;
            if (nodes[cur].next[1 - indx] != -1 && nodes[nodes[cur].next[1 - indx]].cnt) {
                cur = nodes[cur].next[1 - indx];
                ans |= (1 << bit);
            } else {
                cur = nodes[cur].next[indx];
            }
        }
        return ans;
    }
};

void solve() {
    int q;
    cin >> q;

    Trie trie;
    trie.insert(0);

    while (q--) {
        char ch;
        int x;
        cin >> ch >> x;
        if (ch == '+') {
            trie.insert(x);
        } else if (ch == '-') {
            trie.remove(x);
        } else {
            cout << trie.query(x) << nl;
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
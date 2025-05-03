/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Forbidden Prefix

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct Node {
    int cnt;
    bool xEnds;
    int next[26];
    Node() {
        cnt = 0;
        xEnds = false;
        memset(next, -1, sizeof next);
    }
};

struct Trie {
    vector<Node> nodes;
    int nodeCount;
    Trie() {
        nodeCount = 1;
        nodes.resize(1);
    }
    int insertX(const string &s) {
        int cur = 0;
        bool found = false;
        bool created = false;
        vector<int> A;
        for (auto &c : s) {
            int indx = c - 'a';
            if (nodes[cur].next[indx] == -1) {
                nodes.push_back(Node());
                nodes[cur].next[indx] = nodeCount++;
                created = true;
            }
            cur = nodes[cur].next[indx];
            A.push_back(cur);
            found |= nodes[cur].xEnds;
        }
        nodes[cur].xEnds = true;
        
        if (found || created) return 0;
        
        int ans = nodes[cur].cnt;
        for (auto &x : A) {
            nodes[x].cnt -= ans;
        }
        return ans;
    }
    int insertY(const string &s) {
        int cur = 0;
        bool found = false;
        for (auto &c : s) {
            int indx = c - 'a';
            if (nodes[cur].next[indx] == -1) break;
            cur = nodes[cur].next[indx];
            found |= nodes[cur].xEnds;
        }
        
        if (found) return 0;
        
        cur = 0;
        for (auto &c : s) {
            int indx = c - 'a';
            if (nodes[cur].next[indx] == -1) {
                nodes.push_back(Node());
                nodes[cur].next[indx] = nodeCount++;
            }
            cur = nodes[cur].next[indx];
            nodes[cur].cnt++;
        }
        return 1;
    }
};

void solve() {
    int q;
    cin >> q;
    
    Trie trie;
    int ans = 0;
    while (q--) {
        int op;
        string s;
        cin >> op >> s;
        if (op == 1) {
            ans -= trie.insertX(s);
        }
        else {
            ans += trie.insertY(s);
        }
        cout << ans << nl;
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
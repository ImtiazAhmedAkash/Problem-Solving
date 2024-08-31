/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Karuta

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
    int next[26];
    Node() {
        cnt = 0;
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
    void insert(const string& s) {
        int cur = 0;
        for (auto &c : s) {
            int indx = c - 'a';
            if (nodes[cur].next[indx] == -1) {
                nodes[cur].next[indx] = nodeCount++;
                nodes.push_back(Node());
            }
            cur = nodes[cur].next[indx];
            nodes[cur].cnt++;
        }
    }
    int query(const string& s) {
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            int indx = s[i] - 'a';
            cur = nodes[cur].next[indx];
            if (nodes[cur].cnt > 1) {
                ans = max(ans, i + 1);
            }
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    Trie trie;
    vector<string> A(n);
    for (auto &x : A) {
        cin >> x;
        trie.insert(x);
    }
    
    for (auto &x : A) {
        cout << trie.query(x) << nl;
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
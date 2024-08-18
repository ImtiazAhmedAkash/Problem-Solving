/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ADAINDEX - Ada and Indexing

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
    Node* nxt[26];
    int cnt;
    Node() {
        cnt = 0;
        memset(nxt, 0, sizeof nxt);
    }
};

struct Trie {
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(const string& s) {
        Node* cur = root;
        for (auto c : s) {
            int indx = c - 'a';
            if (!cur->nxt[indx]) {
                cur->nxt[indx] = new Node();
            }
            cur = cur->nxt[indx];
            cur->cnt++;
        }
    }
    int query(const string& s) {
        Node* cur = root;
        for (auto c : s) {
            int indx = c - 'a';
            if (!cur->nxt[indx]) {
                return 0;
            }
            cur = cur->nxt[indx];
        }
        return cur->cnt;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    Trie trie;

    while (n--) {
        string s;
        cin >> s;
        trie.insert(s);
    }

    while (q--) {
        string s;
        cin >> s;
        cout << trie.query(s) << nl;
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
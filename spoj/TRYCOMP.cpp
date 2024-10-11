/*  In the Name of ALLAH, the most gracious, the most merciful  */

// TRYCOMP - Try to complete

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 5e6;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(const string& s) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t hash = 0;
        for (char c : s) {
            hash = hash * 31 + c;
        }
        return splitmix64(hash + FIXED_RANDOM);
    }
};

struct Node {
    int nxt[26];
    string str;
    int cnt;
    Node() {
        cnt = 0;
        str = "";
        memset(nxt, -1, sizeof nxt);
    }
};

struct Trie {
    vector<Node> nodes;
    gp_hash_table<string, int, custom_hash> M;
    int nodeCount;
    Trie() {
        nodeCount = 1;
        nodes.resize(1);
    }
    void insert(const string& s) {
        int cur = 0;
        for (auto c : s) {
            int indx = c - 'a';
            if (nodes[cur].nxt[indx] == -1) {
                nodes[cur].nxt[indx] = nodeCount++;
                nodes.push_back(Node());
            }
            cur = nodes[cur].nxt[indx];
        }

        M[s]++;
        cur = 0;
        for (char c : s) {
            int index = c - 'a';
            cur = nodes[cur].nxt[index];
            if (M[s] > nodes[cur].cnt) {
                nodes[cur].cnt = M[s];
                nodes[cur].str = s;
            } else if (M[s] == nodes[cur].cnt) {
                nodes[cur].str = min(nodes[cur].str, s);
            }
        }
    }
    void query(const string& s) {
        int cur = 0;
        for (auto c : s) {
            int indx = c - 'a';
            if (nodes[cur].nxt[indx] == -1) {
                cout << -1 << nl;
                return;
            }
            cur = nodes[cur].nxt[indx];
        }
        cout << nodes[cur].str << " " << nodes[cur].cnt << nl;
    }
};

void solve() {
    int n;
    cin >> n;

    Trie trie;

    while (n--) {
        string s;
        cin >> s;
        trie.insert(s);
    }

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        trie.query(s);
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
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Mystic Runes

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
    int next[10];
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
    void insert(const string& s) {
        int cur = 0;
        for (auto& c : s) {
            int indx = c - '0';
            if (nodes[cur].next[indx] == -1) {
                nodes[cur].next[indx] = nodeCount++;
                nodes.push_back(Node());
            }
            cur = nodes[cur].next[indx];
            nodes[cur].cnt++;
        }
    }
    int query(const string& s) {
        int cur = 0;
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int indx = s[i] - '0';
            if (nodes[cur].next[indx] == -1) {
                break;
            }
            cur = nodes[cur].next[indx];
            if (i + 1 == n) {
                ans = nodes[cur].cnt;
            }
        }
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<char> M(26);
    M[0] = M[1] = M[2] = '2';
    M[3] = M[4] = M[5] = '3';
    M[6] = M[7] = M[8] = '4';
    M[9] = M[10] = M[11] = '5';
    M[12] = M[13] = M[14] = '6';
    M[15] = M[16] = M[17] = M[18] = '7';
    M[19] = M[20] = M[21] = '8';
    M[22] = M[23] = M[24] = M[25] = '9';

    Trie trie;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string t;
        for (auto& c : s) {
            t += M[c - 'a'];
        }
        trie.insert(t);
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
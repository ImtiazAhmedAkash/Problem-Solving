/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cards Query Problem

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 200005
#define deb(x) cerr << #x << " = " << x << nl


void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<multiset<int>> box(N);
    vector<set<int>> card(N);
    
    while(q--) {
        int x, y, z;
        cin >> x >> y;
        
        if (x == 1) {
            cin >> z;
            box[z].insert(y);
            card[y].insert(z);
        }
        else if (x == 2) {
            for (auto i : box[y]) cout << i << " ";
            cout << nl;
        }
        else {
            for (auto i : card[y]) cout << i << " ";
            cout << nl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
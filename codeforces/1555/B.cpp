/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Two Tables

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int room_width, room_height, x1, y1, x2, y2, new_table_height, new_table_width;
    cin >> room_width >> room_height >> x1 >> y1 >> x2 >> y2 >> new_table_width >> new_table_height;
    if (new_table_height + (y2 - y1) > room_height && new_table_width + (x2 - x1) > room_width) {
        cout << -1 << nl;
        return;
    }
    int ans = INF;
    if (new_table_width + (x2 - x1) <= room_width) {
        int right = max(0, new_table_width - x1);
        int left = max(0, x2 - (room_width - new_table_width));
        ans = min({ans, left, right});
    }
    if (new_table_height + (y2 - y1) <= room_height) {
        int up = max(0, new_table_height - y1);
        int down = max(0, y2 - (room_height - new_table_height));
        ans = min({ans, up, down});
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Takahashi is Slime 2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<int> dx = {-1, +0, +1, +0};
vector<int> dy = {+0, +1, +0, -1};

void solve() {
    int h, w, k;
    cin >> h >> w >> k;
    int p, q;
    cin >> p >> q;
    --p, --q;
    vector A(h, vector<ll>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> A[i][j];
        }
    }
    
    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && y >= 0 && x < h && y < w);
    };
    
    vector<pair<int, int>> B;
    vector used(h, vector<bool>(w));
    used[p][q] = true;
    set<pair<ll, int>> st;
    for (int i = 0; i < 4; i++) {
        int nx = p + dx[i];
        int ny = q + dy[i];
        if (isValid(nx, ny) && !used[nx][ny]) {
            st.insert({A[nx][ny], B.size()});
            B.push_back({nx, ny});
            used[nx][ny] = true;
        }
    }
    
    ll ans = A[p][q];
    while (!st.empty()) {
        auto [val, indx] = *st.begin();
        st.erase(st.begin());
        
        if (ans <= (__int128)val * k) break;
        ans += val;
        auto [x, y] = B[indx];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && !used[nx][ny]) {
                st.insert({A[nx][ny], B.size()});
                B.push_back({nx, ny});
                used[nx][ny] = true;
            }
        }
    }
    
    cout << ans << nl;
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
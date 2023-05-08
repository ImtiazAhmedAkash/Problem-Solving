/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cross

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Lets say, w = width of a grid, h = height of the grid.
 * The task is to find how many crosses of order n are in the grid, where n = min(w, h).
 * 
 * First of all find the center of a cross.
 * An interesting observation: 
 * The center can not be in the (first column or first row or last column or last row).
 * Thats why the loop are from 1 to (h - 1) or 1 to (w - 1).
 * 
 * After finding the center, check the order of the cross.
 * A direction array can be used to check the four corner cell.
 * As long as the four corner cell has the element '#', keep checking and count the order.
 * If a cell goes out the grid or the cell has a '.', stop the checking.
 * Increment the order of the cross (in the ans vector) by 1.
 * 
 * When all checking is done, print the vector from index 1 till the end.
 * Because the 0-th index contains the number of crosses of 0x0 size which is unnecessary for the problem.
 */

// direction array
int dr[] = {-1, 1, 1, -1};
int dc[] = {-1, -1, 1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    char grid[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> grid[i][j];
    }

    vector<int> ans(min(w, h) + 1);

    for (int i = 1; i + 1 < h; i++) {
        for (int j = 1; j + 1 < w; j++) {
            if (grid[i][j] == '#') {
                bool ok = true;
                int cnt = 0;

                while (1) {
                    for (int k = 0; k < 4; k++) {
                        int nr = i + (cnt + 1) * dr[k];
                        int nc = j + (cnt + 1) * dc[k];

                        if (nr < 0 || nc < 0 || nr >= h || nc >= w || grid[nr][nc] == '.') {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        ans[cnt]++;
                        break;
                    }
                    cnt++;
                }
            }
        }
    }

    for (int i = 1; i < ans.size(); i++) cout << ans[i] << " ";
    cout << nl;

    return 0;
}
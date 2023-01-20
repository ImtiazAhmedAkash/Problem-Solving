/*  In the name of ALLAH, the most gracious, the most merciful  */

// Stripes

#include <bits/stdc++.h>
using namespace std;

/*
 * Take all the inputs in a 2D array.
 * The rows are painted Red, and the columns are painted Blue.
 * 
 * If a row is painted last, then it would contain 8 'R'.
 * So, if no row contains 8 'R', then Red color is not painted last. 
 * Rather, the Blue color is painted last. The vice versa in true too for each column.
 * 
 * For all the rows, if all the elements are 'R', cnt('R') == 8, then print 'R'.
 * Otherwise, print 'B'.
 */

string solve() {
    char arr[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < 8; i++) {
        int cnt = 0;

        for (int j = 0; j < 8; j++) {
            if (arr[i][j] != 'R')
                break;
            cnt++;
            if (cnt == 8)
                return "R";
        }
    }
    return "B";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';

    return 0;
}
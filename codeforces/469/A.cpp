/*  In the Name of ALLAH, the most gracious, the most merciful  */

// I Wanna Be the Guy

#include <bits/stdc++.h>
using namespace std;

/*
 * Use a loop for two friends.
 * Take all the input values in a set.
 * If the set size is equal to n (total number of levels),
 * they can pass or finish the game, otherwise, they can't.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    set<int> s;

    for (int i = 0; i < 2; i++) {
        int t, val;
        cin >> t;

        while (t--) {
            cin >> val;
            s.insert(val);
        }
    }

    if (s.size() == n)
        cout << "I become the guy." << '\n';
    else
        cout << "Oh, my keyboard!" << '\n';

    return 0;
}
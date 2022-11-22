// Is your horseshoe on the other hoof?

#include <bits/stdc++.h>
using namespace std;

/*
 * Take all the inputs in a set.
 * Set stores all the distinct elements.
 * The answer is 4 - s.size().
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<int> s;
    int val;

    for (int i = 0; i < 4; i++)
    {
        cin >> val;
        s.insert(val);
    }

    cout << 4 - s.size() << "\n";

    return 0;
}

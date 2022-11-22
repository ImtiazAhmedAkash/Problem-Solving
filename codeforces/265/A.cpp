// Colurful Stones (Simplified Edition)

#include <bits/stdc++.h>
using namespace std;

/*
 * Iterate a loop from 0 to instruction string's size.
 * If ins[i] and str[index] is the same,
 * Liss will move to the next stone.
 * In that case, increment the index by 1.
 * As 0-indexed string is used, the answer will be index + 1.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str, ins;
    cin >> str >> ins;

    int index = 0;

    for (int i = 0; i < ins.size(); i++)
    {
        if (ins[i] == str[index])
            index++;
    }

    cout << index + 1 << "\n";

    return 0;
}
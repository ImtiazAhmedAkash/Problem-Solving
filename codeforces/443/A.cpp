// Anton and Letters

#include <bits/stdc++.h>
using namespace std;

/*
 * In a set, all the elements are distinct.
 * Take input until closing curly bracket '}' is found.
 * If input is a small letter, insert it into the set.
 * The size of the set is the answer.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<char> s;
    char input;

    while (1)
    {
        cin >> input;
        if (input == '}')
            break;
        else if (input >= 'a' && input <= 'z')
            s.insert(input);
    }

    cout << s.size() << '\n';

    return 0;
}
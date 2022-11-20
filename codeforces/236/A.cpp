// Boy or Girl

#include <bits/stdc++.h>
using namespace std;

/*
 * Take all the characters of the input string in a set.
 * Set only contains the distinct characters.
 * If the set size is odd, the person is a male.
 * Otherwise, the person is a female.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    set<char> s;
    for (auto i : str)
        s.insert(i);

    if (s.size() % 2)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";

    return 0;
}
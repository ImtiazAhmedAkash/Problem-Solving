// Spell Check

#include <bits/stdc++.h>
using namespace std;

/*
 * Take a string (value) that contains the name as sorted.
 * The sorted version of Timur is "Timru".
 * 
 * Take a string, sort it.
 * If the sorted string is the same as value, print "YES".
 * Otherwise, print "NO".
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str, value = "Timru";

    int test, length;
    cin >> test;
    while (test--)
    {

        cin >> length;
        cin >> str;
        sort(str.begin(), str.end());

        if (str == value)
            cout << "YES" << "\n";
        else
            cout << "NO"  << "\n";
    }

    return 0;
}
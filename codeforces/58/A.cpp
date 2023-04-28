/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Chat Room

#include <bits/stdc++.h>
using namespace std;

/*
 * Take a string "a" as "hello".
 * Iterate in the given string "str"
 * and check if the characters of string "a" can be found as a subsequence.
 * It is not necessary for the elements to be consecutive.
 *
 * If an element of "a" is found, check for the next element.
 * If all of the elements of "a" is found, the index will be equal to a.size().
 * In this case, the answer is "YES".
 * 
 * If after iterating the entire "str", the index is not equal to a.size(), then the answer is "NO".
 */

string solve() {
    string str, a = "hello";
    cin >> str;
    int index = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == a[index])
            index++;
        if (index == a.size())
            return "YES";
    }
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << solve() << '\n';

    return 0;
}
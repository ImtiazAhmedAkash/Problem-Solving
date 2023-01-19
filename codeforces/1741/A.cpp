/*  In the name of ALLAH, the most gracious, the most merciful  */

// Compare T-Shirt Sizes

#include <bits/stdc++.h>
using namespace std;

/*
 * If the given two strings are equal, return "=".
 * 
 * If the last element of str1 is less than that of str2, return ">".
 * Because lexicographically, S > M > L, but the order is S < M < L in T-shirt sizes.
 * 
 * If the last element of both strings are equal, there are two cases where str1 > str2.
 * If the last element is 'L', then the bigger the string size, the bigger the shirt size.
 * Else if the last element is 'S', the the bigger the string size, the smaller the shirt size.
 * For this two cases, return ">".
 * 
 * If none of this condition is true, then the str2 is bigger than str1. So, return "<".
 */

char solve() {
    string str1, str2;
    cin >> str1 >> str2;

    if (str1 == str2)
        return '=';

    if (str1.back() < str2.back())
        return '>';

    if (str1.back() == str2.back()) {
        if (str1.back() == 'L' && str1.size() > str2.size())
            return '>';
        else if (str1.back() == 'S' && str1.size() < str2.size())
            return '>';
    }

    return '<';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }

    return 0;
}
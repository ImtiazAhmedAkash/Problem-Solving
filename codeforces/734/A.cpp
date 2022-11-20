// Anton and Danik

#include <bits/stdc++.h>
using namespace std;

/*
 * First of all, allocate n memory dynamically.
 * Then, count 'A' and 'D'.
 * if A is greater than D, print "Anton",
 * else if D is greater than A, print "Danik",
 * else print "Friendship".
 */

int main()
{
    int n;
    cin >> n;

    char *ptr = (char *)malloc(n * sizeof(char));

    int a = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ptr[i];

        (ptr[i] == 'A') ? a++ : d++;
    }

    if (a == d)
        cout << "Friendship" << endl;
    else
        (a > d) ? cout << "Anton\n" : cout << "Danik\n";

    free(ptr);

    return 0;
}

// Games

#include <bits/stdc++.h>
using namespace std;

/*
 * Store home and away jersey codes in two arrays.
 * For each home jersey, compare it with the away jersey.
 * If the colors are the same, count.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int home[n], away[n];

    for (int i = 0; i < n; i++)
    {
        cin >> home[i] >> away[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (home[i] == away[j])
                count++;
        }
    }

    cout << count << "\n";

    return 0;
}
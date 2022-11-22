// Police Recruits

#include <bits/stdc++.h>
using namespace std;

/*
 * Sum up all the events one by one.
 * If the sum stays non-negative (sum >= 0),
 * crimes will be handled.
 * 
 * If the sum becomes negative (sum < 0),
 * crimes will go untreated. 
 * Count the untreated situations and initialize sum as 0.
 * In this problem, crimes cannot pile up, police officers can.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int sum = 0, count = 0;
    while (n--)
    {
        int event;
        cin >> event;
        sum += event;

        if (sum < 0)
        {
            count++;
            sum = 0;
        }
    }

    cout << count << "\n";

    return 0;
}
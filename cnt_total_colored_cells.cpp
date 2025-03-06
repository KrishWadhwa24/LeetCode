#include <bits/stdc++.h>
using namespace std;

/*
There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:

At the first minute, color any arbitrary unit cell blue.
Every minute thereafter, color blue every uncolored cell that touches a blue cell.
Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.


Return the number of colored cells at the end of n minutes.



Example 1:

Input: n = 1
Output: 1
Explanation: After 1 minute, there is only 1 blue cell, so we return 1.
Example 2:

Input: n = 2
Output: 5
Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5.


Constraints:

1 <= n <= 10^5
*/

class Solution
{
public:
    long long coloredCells(int n)
    {
        return 1 + (long long)n * (n - 1) * 2;
    }
};

/*
Time Complexity: O(1)
Space Complexity: O(1)
*/

/*

typedef long long int ll;
class Solution {
public:
    long long coloredCells(int n) {
        int start  = 2*n;
        ll sum  = 0;

        for(int i =1;i<2*n;i+=2)
        {
            if(i==1)
            {
                sum+=(2*n-i);
            }else
            if(2*n-i>0)
            {
                sum+=(2*(2*n-i));
            }
        }
        return sum;
    }
};
*/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

int main()
{
    Solution s;
    cout << s.coloredCells(1) << endl;
    cout << s.coloredCells(100) << endl;
    return 0;
}
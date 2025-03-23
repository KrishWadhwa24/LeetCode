#include <bits/stdc++.h>
using namespace std;

/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.



Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.


Constraints:

n == ratings.length
1 <= n <= 2 * 10^4
0 <= ratings[i] <= 2 * 10^4

*/

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while (i < n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                sum++;
                i++;
            }
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1])
            {
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1])
            {
                sum += down;
                down++;
                i++;
            }

            if (down > peak)
            {
                sum += (down - peak);
            }
        }
        return sum;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/


/*
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> prefix(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                prefix[i] = prefix[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                prefix[i] = max(prefix[i], prefix[i + 1] + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += prefix[i];
        }
        return ans;
    }
};


Time Complexity: O(N)
Space Complexity: O(N)
*/

int main()
{
    vector<int> ratings = {0,2,4,7,6,5,4,3,2,1,1,1,2,3,4,2,1,1,1};
    Solution obj;
    cout << obj.candy(ratings) << endl;
    return 0;
}
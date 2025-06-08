#include<bits/stdc++.h>
using namespace std;


/*
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space.



Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]


Constraints:

1 <= n <= 5 * 10^4

*/

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> arr;
        int curr = 1;

        for (int i = 0; i < n; i++)
        {
            arr.push_back(curr);

            if (curr * 10 <= n)
            {
                curr *= 10;
            }
            else
            {
                while (curr % 10 == 9 || curr >= n)
                {
                    curr /= 10;
                }
                curr++;
            }
        }
        return arr;
    }
};

/*
Time Complexity: O(n) since we are generating numbers in lexicographical order without sorting.
Space Complexity: O(n) for storing the result in the vector.
*/

/*

class Solution {
private:
    void recur(int n, vector<int>& arr, int result) {
        if (result > n) return;

        arr.push_back(result);

        for (int i = 0; i <= 9; i++) {
            int next = result * 10 + i;
            if (next > n) return;
            recur(n, arr, next);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> arr;
        for (int i = 1; i <= 9; i++) {
            recur(n, arr, i);
        }
        return arr;
    }
};

Time Complexity: O(n) since we are generating numbers in lexicographical order without sorting.
Space Complexity: O(n) for storing the result in the vector.

*/

/*

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> vec;

        for(int i =1;i<=n;i++)
        {
            string str = to_string(i);
            vec.push_back(str);
        }

        sort(vec.begin(),vec.end());
        vector<int> arr;
        for(int i =0;i<vec.size();i++)
        {
            arr.push_back(std::stoi(vec[i]));
        }
        return arr;
    }
};

Time Complexity: O(n log n) due to sorting the strings.
Space Complexity: O(n) for storing the strings in the vector.
*/


//Example usage:
int main() {
    Solution sol;
    int n = 4400;
    vector<int> result = sol.lexicalOrder(n);
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
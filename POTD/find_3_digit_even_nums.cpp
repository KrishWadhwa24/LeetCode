#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.



Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array.
Notice that there are no odd integers or integers with leading zeros.
Example 2:

Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits.
In this example, the digit 8 is used twice each time in 288, 828, and 882.
Example 3:

Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.


Constraints:

3 <= digits.length <= 100
0 <= digits[i] <= 9
*/

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        unordered_map<int, int> mpp;
        int n = digits.size();
        for (int i = 0; i < n; i++)
        {
            mpp[digits[i]]++;
        }
        vector<int> ans;
        for (int i = 100; i < 1000; i += 2)
        {
            string str = to_string(i);
            if (mpp.find(str[0] - '0') != mpp.end())
            {
                mpp[str[0] - '0']--;
                if (mpp[str[0] - '0'] == 0)
                {
                    mpp.erase(str[0] - '0');
                }

                if (mpp.find(str[1] - '0') != mpp.end())
                {
                    mpp[str[1] - '0']--;
                    if (mpp[str[1] - '0'] == 0)
                    {
                        mpp.erase(str[1] - '0');
                    }

                    if (mpp.find(str[2] - '0') != mpp.end())
                    {
                        ans.push_back(i);
                    }
                    mpp[str[1] - '0']++;
                }
                mpp[str[0] - '0']++;
            }
        }
        return ans;
    }
};
/*
Time Complexity: - O(1000)
Space Complexity :- O(n);
*/


/*
class Solution {
public:
    void solve(int cur,int k,vector<int> &freq,vector<int> &res){
        if(k==0){
            if(cur%2==0)
                res.push_back(cur);
            return;
        }
        cur=cur*10;
        for(int i=0;i<=9;i++){
            if(cur==0 && i==0)
                continue;
            if(freq[i]>0){
                freq[i]--;
                solve(cur+i,k-1,freq,res);
                freq[i]++;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
       vector<int> res;
       vector<int> freq(10,0);
       for(auto d:digits)
        freq[d]++; 
        solve(0,3,freq,res);
        return res;
    }
};

Time Complexity: O(10^3)
Space Complexity: O(1)

*/

int main()
{
    Solution s;
    vector<int> digits = {2, 1, 3, 0};
    vector<int> result = s.findEvenNumbers(digits);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.



Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.


Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.
*/

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string res = "";
        for (int i = 0; i < nums.size(); i++)
        {
            res += nums[i][i] == '1' ? '0' : '1';
        }
        return res;
    }
};

/*
Time complexity: O(n)
Space complexity: O(n)
*/

/*

class Solution {
    private:
    bool backtrack(string& str,unordered_set<string>& st,int index,int n)
    {
        if(index==n)
        {
            if(st.find(str)==st.end())
            {
                return true;
            }else
            {
                return false;
            }
        }
        str.push_back('0');
        if(backtrack(str,st,index+1,n))
        return true;
        str.pop_back();
        str.push_back('1');
        if(backtrack(str,st,index+1,n))
        return true;
        str.pop_back();

        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].length();
        string str;
        unordered_set<string> st;
        for(auto it:nums)
        {
            st.insert(it);
        }
        backtrack(str,st,0,n);
        return str;
    }
};

Time complexity: O(2^n)
Space complexity: O(2^n)
*/

int main()
{
    vector<string> nums = {"111", "011", "001"};
    Solution s;
    cout << s.findDifferentBinaryString(nums) << endl;
    return 0;
}
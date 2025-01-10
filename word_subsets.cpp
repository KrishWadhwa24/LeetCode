#include <bits/stdc++.h>
using namespace std;

/*
You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.



Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]


Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.

*/

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        int cnt[26] = {0};
        int t[26];
        for (auto &it : words2)
        {
            memset(t, 0, sizeof t);
            for (auto &ch : it)
            {
                t[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                cnt[i] = max(cnt[i], t[i]);
            }
        }

        vector<string> ans;
        for (auto &it : words1)
        {
            memset(t, 0, sizeof t);
            for (auto &ch : it)
            {
                t[ch - 'a']++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++)
            {
                if (t[i] < cnt[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(it);
        }
        return ans;
    }
};
/*
Time complexity : O(N+M) where N is the size of words1 and M is the size of words2
Space complexity : O(52) as we are using constant space

*/

// class Solution {
// public:
//     vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
//         unordered_map<char,int> mpp;
//         vector<string> ans;
//         for(auto it:words2)
//         {
//             unordered_map<char,int> freq;
//             for(int i = 0;i<it.length();i++)
//             {
//                 freq[it[i]]++;
//                 mpp[it[i]] = max(mpp[it[i]],freq[it[i]]);
//             }
//         }

//         for(auto it:words1)
//         {
//             unordered_map<char,int> check;
//             for(int i =0;i<it.length();i++)
//             {
//                 check[it[i]]++;
//             }
//             bool flag = true;
//             for(auto x:mpp)
//             {
//                     if(check[x.first]<x.second){
//                     flag = false;
//                     break;
//             }
//             }
//             if(flag)
//             ans.push_back(it);
//         }
//         return ans;
//     }
// };

/*
Time complexity : O(N+M) where N is the size of words1 and M is the size of words2
Space complexity : O(26+26+26+K(number of elements in ans)) as we are using constant space

*/

int main()
{
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};
    Solution obj;
    vector<string> ans = obj.wordSubsets(words1, words2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
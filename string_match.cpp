#include<bits/stdc++.h>
using namespace std;

/*
Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.
*/


class Solution {
public:
bool match(string word1,string word2)
{
    int sz = word1.length();
    int s2 = word2.length();
    for(int i =0;i<=s2-sz;i++)
    {
        int j=0;
        while(j<sz && word1[j]==word2[i+j])
        {
            j++;
        }
        if(j==sz)
        return true;
    }
    return false;
}
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;

        int n = words.size();
        for(int i =0;i<n;i++)
        {
            string word = words[i];
            for(int j =0;j<n;j++)
            {
                if(i!=j && match(word,words[j])==true)
                {
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"mass","as","hero","superhero"};
    vector<string> ans = s.stringMatching(words);
    for(auto x: ans)
    {
        cout<<x<<" ";
    }
    return 0;
}
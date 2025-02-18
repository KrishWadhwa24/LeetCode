#include<bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].
Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].
 

Constraints:

1 <= words.length <= 10^5
1 <= words[i].length <= 40
words[i] consists only of lowercase English letters.
sum(words[i].length) <= 3 * 10^5
1 <= queries.length <= 10^5
0 <= li <= ri < words.length

*/


class Solution {
public:
bool check(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    return true;
    else
    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> mark(words.size(),0);
        for(int i =0;i<words.size();i++)
        {
            int j = words[i].size()-1;
            if(check(words[i][0]) && check(words[i][j]))
            mark[i]=1;
        }
        for(int i =1;i<mark.size();i++)
        {
            mark[i] = mark[i-1]+mark[i];
        }
        vector<int> res;
        for(auto it:queries)
        {
            int l = it[0];
            int r = it[1];

            int ans = l==0?mark[r]:mark[r]-mark[l-1];
            res.push_back(ans);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
    vector<int> res = s.vowelStrings(words,queries);
    for(auto it:res)
    cout<<it<<" ";
    cout<<endl;
    return 0;
}
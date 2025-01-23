#include<bits/stdc++.h>
using namespace std;

/*
Given a sorted dictionary of an alien language having some words dict and k starting alphabets of a standard dictionary. Find the order of characters in the alien language. If no valid ordering of letters is possible, then return an empty string.

Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be "true" if the order of string returned by the function is correct else "false" denotes incorrect string returned.

Examples:

Input: dict[] = ["baa","abcd","abca","cab","cad"], k = 4
Output: true
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Input: dict[] = ["caa","aaa","aab"], k = 3
Output: true
Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
Input: dict[] = ["dhhid","dahi","cedg","fg","gdah","i","gbdei","hbgf","e","ddde"], k = 9 
Output: false
Constraints:
1 ≤ dict.size()≤ 10^4
1 ≤ k ≤ 26
1 ≤ Length of words ≤ 50
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  string topo(int V,vector<vector<int>>& adj)
  {
      int indegree[V]={0};
      for(int i =0;i<V;i++)
      {
          for(auto it:adj[i])
          indegree[it]++;
      }
      
      queue<int> q;
      for(int i=0;i<V;i++)
      {
          if(indegree[i]==0)
          q.push(i);
      }
      
      string ans;
      while(!q.empty())
      {
          int node = q.front();
          q.pop();
          
          ans += (char)(node+'a');
          for(auto it:adj[node])
          {
              indegree[it]--;
              if(indegree[it]==0)
              q.push(it);
          }
      }
      return ans;
  }
    string findOrder(vector<string> dict, int k) {
        vector<vector<int>> adj(k);
        int V = dict.size();
        
        for(int i =0;i<V-1;i++)
        {
            string word = dict[i];
            string next = dict[i+1];
            
            for(int j =0;j<min(word.size(),next.size());j++)
            {
                if(word[j]!=next[j])
                {
                    adj[word[j]-'a'].push_back(next[j]-'a');
                    break;
                }
            }
        }
        return topo(k,adj);
        
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<string> dict(n);
        for (int i = 0; i < n; i++)
        {
            cin >> dict[i];
        }
        Solution obj;
        string order = obj.findOrder(dict, k);
        string temp = order;
        sort(temp.begin(), temp.end());
        bool f = true;
        if (temp.length() != order.length())
        {
            f = false;
        }
        else
        {
            for (int i = 0; i < temp.length(); i++)
            {
                if (temp[i] != order[i])
                {
                    f = false;
                    break;
                }
            }
        }
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
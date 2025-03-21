#include <bits/stdc++.h>
using namespace std;

/*
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.



Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".


Constraints:

n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.
*/

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes,
                                  vector<vector<string>> &ingredients,
                                  vector<string> &supplies)
    {
        int cnt = 0;
        unordered_map<string, int> mpp;
        unordered_map<int, string> check;

        for (int i = 0; i < recipes.size(); i++)
        {
            check[cnt] = recipes[i];
            mpp[recipes[i]] = cnt++;
        }

        vector<vector<int>> adj(cnt + ingredients.size());
        vector<int> indegree(cnt + ingredients.size(), 0);

        unordered_set<string> mpp2;
        for (auto &it : supplies)
        {
            mpp2.insert(it);
        }

        for (int i = 0; i < recipes.size(); i++)
        {
            for (auto &ingredient : ingredients[i])
            {
                if (mpp.find(ingredient) != mpp.end())
                {
                    adj[mpp[ingredient]].push_back(mpp[recipes[i]]);
                    indegree[mpp[recipes[i]]]++;
                }
                else if (mpp2.find(ingredient) == mpp2.end())
                {
                    check[cnt] = ingredient;
                    mpp[ingredient] = cnt++;
                    adj[mpp[ingredient]].push_back(mpp[recipes[i]]);
                    indegree[mpp[recipes[i]]]++;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < recipes.size(); i++)
        {
            if (indegree[mpp[recipes[i]]] == 0)
            {
                q.push(mpp[recipes[i]]);
            }
        }

        vector<string> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            string recipe = check[node];
            if (mpp.find(recipe) != mpp.end())
            {
                ans.push_back(recipe);
            }
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(N + M), where N is the number of recipes and M is the number of ingredients.
Space Complexity: O(N + M)
*/

int main()
{
    Solution s;
    vector<string> recipes = {"bread", "sandwich", "burger"};
    vector<vector<string>> ingredients = {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}};
    vector<string> supplies = {"yeast", "flour", "meat"};
    vector<string> ans = s.findAllRecipes(recipes, ingredients, supplies);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0; 
}
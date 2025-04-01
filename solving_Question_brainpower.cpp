#include <bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.



Example 1:

Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
Example 2:

Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.


Constraints:

1 <= questions.length <= 10^5
questions[i].length == 2
1 <= pointsi, brainpoweri <= 10^5

*/



//Tabulation Approach

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long int> dp(n, -1);
        dp[n - 1] = questions[n - 1][0];

        for (int i = n - 2; i >= 0; i--)
        {
            long long int take = questions[i][0];
            if (i + questions[i][1] < n - 1)
                take += dp[i + questions[i][1] + 1];

            long long int nottake = dp[i + 1];

            dp[i] = max(take, nottake);
        }

        return dp[0];
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n) for dp array
*/


/*

Memoization Approach

class Solution {
    private:
    long long int recur(vector<vector<int>>& questions,int n,int ind,vector<long long int>& dp)
    {
        if(ind>=n)
        return 0;

        if(dp[ind]!=-1)
        return dp[ind];

        auto it = questions[ind];
        auto take = it[0]+recur(questions,n,ind+it[1]+1,dp);
        long long int nottake = recur(questions,n,ind+1,dp);

        return dp[ind] = max(take,nottake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long int> dp(n,-1);
        long long maxi = recur(questions,n,0,dp);
        return maxi;
    }
};

Time Complexity: O(n)
Space Complexity: O(n) + O(n) = O(n) for recursion stack and dp array

*/


/*
Backtracking Approach

class Solution {
    private:
    long long int recur(vector<vector<int>>& questions,int n,int ind)
    {
        if(ind>=n)
        return 0;

        auto it = questions[ind];
        auto take = it[0]+recur(questions,n,ind+it[1]+1);
        long long int nottake = recur(questions,n,ind+1);

        return max(take,nottake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long maxi = recur(questions,n,0);
        return maxi;
    }
};

Time Complexity: O(2^n)
Space Complexity: O(n) + O(n) = O(n) for recursion stack and dp array

*/

int main()
{
    Solution s;
    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << s.mostPoints(questions) << endl; // Output: 5
    return 0;
}
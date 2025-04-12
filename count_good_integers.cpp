#include <bits/stdc++.h>
using namespace std;

/*
You are given two positive integers n and k.

An integer x is called k-palindromic if:

x is a palindrome.
x is divisible by k.
An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.

Return the count of good integers containing n digits.

Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.



Example 1:

Input: n = 3, k = 5

Output: 27

Explanation:

Some of the good integers are:

551 because it can be rearranged to form 515.
525 because it is already k-palindromic.
Example 2:

Input: n = 1, k = 4

Output: 2

Explanation:

The two good integers are 4 and 8.

Example 3:

Input: n = 5, k = 6

Output: 2468



Constraints:

1 <= n <= 10
1 <= k <= 9

*/

class Solution
{
private:
    vector<long long int> factorial()
    {
        vector<long long int> fact;
        fact.push_back(1);
        for (int i = 1; i <= 10; i++)
        {
            fact.push_back(fact.back() * i);
        }
        return fact;
    }

    void recursion(string &str, int n, int k, int ind,
                   const vector<long long> &fact, long long &cnt,
                   unordered_set<string> &st)
    {
        if (ind < 0)
        {
            long long int num = stoll(str);
            if (num % k == 0)
            {

                string sortedStr = str;
                sort(sortedStr.begin(), sortedStr.end());

                if (st.find(sortedStr) == st.end())
                {
                    st.insert(sortedStr);

                    unordered_map<char, int> mpp;
                    for (auto &ch : str)
                        mpp[ch]++;

                    long long totalPerm = fact[n];
                    for (auto &it : mpp)
                    {
                        totalPerm /= fact[it.second];
                    }

                    long long invalid = 0;
                    if (mpp['0'] > 0)
                    {
                        mpp['0']--;
                        long long bad = fact[n - 1];
                        for (auto &it : mpp)
                        {
                            bad /= fact[it.second];
                        }
                        invalid = bad;
                    }

                    cnt += totalPerm - invalid;
                }
                else
                {
                    return;
                }
            }
            return;
        }
        int i = 0;
        if (ind == 0)
            i = 1;
        for (; i <= 9; i++)
        {
            str[ind] = i + '0';
            str[n - ind - 1] = i + '0';
            recursion(str, n, k, ind - 1, fact, cnt, st);
        }
    }

public:
    long long countGoodIntegers(int n, int k)
    {
        vector<long long int> fact = factorial();
        int mid = n % 2 == 0 ? n / 2 - 1 : n / 2;
        string s(n, ' ');
        unordered_set<string> st;
        long long int cnt = 0;

        recursion(s, n, k, mid, fact, cnt, st);
        return cnt;
    }
};

/*
Time Complexity: O(9^n) for recursion and O(n) for factorial calculation.
Space Complexity: O(n) for recursion stack space.
*/

int main()
{
    Solution obj;
    int n = 3, k = 5;
    cout << obj.countGoodIntegers(n, k) << endl; // Output: 27
    return 0;
}
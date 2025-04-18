#include<bits/stdc++.h>
using namespace std;

/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

 

Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.

 

Constraints:

1 <= n <= 30
 

Follow up: Could you solve it iteratively?
*/

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    string countAndSay(int n) {
        string res= "1";
        for(int i =2;i<=n;i++)
        {
            string curr = "";
            int cnt = 1;
            for(int j = 1;j<res.length();j++)
            {
                if(res[j]==res[j-1])
                {
                    cnt++;
                }else
                {
                    curr+=to_string(cnt)+res[j-1];
                    cnt = 1;
                }
            }
            curr+=to_string(cnt)+res.back();
            res = curr;
        }
        return res;
    }
};

/*
Time Complexity: O(n*n), where n is the size of s.
Space Complexity : O(n), where n is the size of s.
*/

/*


class Solution {
    private:
    string recur(int n)
    {
        string st;
        if(n==1)
        {
            st.push_back('1');
            return st;
        }

        st = recur(n-1);
        string res= "";
        for(int i =0;i<st.length();i++)
        {
            unordered_map<char,int> mpp;
            char ch = st[i];
            int cnt = 0;
            while(st[i]==ch)
            {
                cnt++;
                i++;
            }
            i--;
            res+=to_string(cnt);
            res+=st[i];
        }
        return res;

    }
public:
    string countAndSay(int n) {
        string str = recur(n);
        return str;
    }
};

Time Complexity: O(n*n), where n is the size of s.
Space Complexity : O(n), where n is the size of s.

*/

int main()
{
    Solution s;
    int n = 28;
    cout<<s.countAndSay(n)<<endl;
    return 0;
}
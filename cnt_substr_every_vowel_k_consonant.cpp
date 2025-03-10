#include <bits/stdc++.h>
using namespace std;

/*
You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.



Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".


Constraints:

5 <= word.length <= 2 * 10^5
word consists only of lowercase English letters.
0 <= k <= word.length - 5
*/

typedef long long int ll;
static auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
private:
    ll count(string &word, int k)
    {
        ll l = 0;
        ll r = 0;

        ll consonant = 0;
        unordered_map<char, int> mpp;
        ll n = word.length();
        ll cnt = 0;

        while (r < n)
        {
            if (word[r] == 'a' || word[r] == 'e' || word[r] == 'i' ||
                word[r] == 'o' || word[r] == 'u')
            {
                mpp[word[r]]++;
            }
            else
            {
                consonant++;
            }

            while (mpp.size() == 5 && consonant >= k)
            {
                cnt += (word.size() - r);
                char ch = word[l];
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u')
                {
                    mpp[ch]--;
                    if (mpp[ch] == 0)
                        mpp.erase(ch);
                }
                else
                {
                    consonant--;
                }
                l++;
            }

            r++;
        }
        return cnt;
    }

public:
    long long countOfSubstrings(string word, int k)
    {
        return count(word, k) - count(word, k + 1);
    }
};

/*
Time Complexity: O(N), where N is the length of the word.
Space Complexity: O(1).
*/

int main()
{
    Solution s;
    string word = "iqeaouqi";
    int k = 2;
    cout << s.countOfSubstrings(word, k) << endl;
    return 0;
}
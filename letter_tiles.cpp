#include<bits/stdc++.h>
using namespace std;

/*
You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: tiles = "AAABBC"
Output: 188
Example 3:

Input: tiles = "V"
Output: 1
 

Constraints:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.

*/

class Solution
{
private:
    int backtrack(int mpp[26])
    {
        int totalCnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (mpp[i] == 0)
                continue;

            totalCnt++;
            mpp[i]--;
            totalCnt += backtrack(mpp);
            mpp[i]++;
        }
        return totalCnt;
    }

public:
    int numTilePossibilities(string tiles)
    {
        int mpp[26] = {0};
        for (auto it : tiles)
        {
            mpp[it - 'A']++;
        }

        return backtrack(mpp);
    }
};

/*
Time Complexity: O(2^n) or O(k!) where k is the number of unique characters in the input string.
Space Complexity: O(1)
*/

/*
class Solution {
private:
    void backtrack(int index, string& tiles, int& cnt, int n) {
        for (int i = index; i < n; i++) {
            bool flag = true;
            for (int j = i + 1; j < n; j++) {
                if (tiles[i] == tiles[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                cnt++;
                swap(tiles[i],tiles[index]);
                backtrack(index+1,tiles,cnt,n);
                swap(tiles[i],tiles[index]);
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        int cnt = 0;
        backtrack(0, tiles, cnt, n);
        return cnt;
    }
};

Time Complexity: O(n!)
Space Complexity: O(1)

*/

int main()
{
    Solution s;
    cout << s.numTilePossibilities("AAB") << endl;
    cout << s.numTilePossibilities("AAABBC") << endl;
    cout << s.numTilePossibilities("V") << endl;
    return 0;
}
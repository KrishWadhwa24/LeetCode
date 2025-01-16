#include<bits/stdc++.h>
using namespace std;

/*
Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

 

Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
 

Constraints:

1 <= num1, num2 <= 10^9

*/

class Solution {
private:
    int binaryStringToDecimal(const std::string& binaryString) {
        int decimalNumber = 0;
        
        for (int i = 0; i < binaryString.length(); ++i) {
            int bit = binaryString[binaryString.length() - 1 - i] - '0';
            decimalNumber += bit * std::pow(2, i);
        }
        
        return decimalNumber;
    }
    
    std::string decimalToBinaryString(int decimalNumber) {
        std::string binaryString;

        while (decimalNumber > 0) {
            binaryString = std::to_string(decimalNumber % 2) + binaryString;
            decimalNumber /= 2;
        }

        if (binaryString.empty()) {
            binaryString = "0";
        }
        
        return binaryString;
    }

public:
    int minimizeXor(int num1, int num2) {
        if (num1 == 0) return 0;
        
        string str = decimalToBinaryString(num1);
        string str2 = decimalToBinaryString(num2);
        
        int cnt21 = 0;
        for(char c : str2) {
            if(c == '1') cnt21++;
        }
        
        string res = str;
        
        for(int i = 0; i < res.length() && cnt21 >= 0; i++) {
            if(res[i] == '1') {
                if(cnt21 > 0) {
                    cnt21--;
                } else {
                    res[i] = '0';
                }
            }
        }
        
        for(int i = res.length() - 1; i >= 0 && cnt21 > 0; i--) {
            if(res[i] == '0') {
                res[i] = '1';
                cnt21--;
            }
        }

        while(cnt21 > 0) {
            res = "1" + res;
            cnt21--;
        }
        
        return binaryStringToDecimal(res);
    }
};

/*
Time Complexity: O(log(num1))
Space Complexity: O(log(num1))
*/

int main() {
    Solution s;
    int num1 = 3, num2 = 5;
    cout << s.minimizeXor(num1, num2) << endl;
    return 0;
}
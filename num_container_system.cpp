#include<bits/stdc++.h>
using namespace std;

/*
Design a number container system that can do the following:

Insert or Replace a number at the given index in the system.
Return the smallest index for the given number in the system.
Implement the NumberContainers class:

NumberContainers() Initializes the number container system.
void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.
 

Example 1:

Input
["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
Output
[null, -1, null, null, null, null, 1, null, 2]

Explanation
NumberContainers nc = new NumberContainers();
nc.find(10); // There is no index that is filled with number 10. Therefore, we return -1.
nc.change(2, 10); // Your container at index 2 will be filled with number 10.
nc.change(1, 10); // Your container at index 1 will be filled with number 10.
nc.change(3, 10); // Your container at index 3 will be filled with number 10.
nc.change(5, 10); // Your container at index 5 will be filled with number 10.
nc.find(10); // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index that is filled with 10 is 1, we return 1.
nc.change(1, 20); // Your container at index 1 will be filled with number 20. Note that index 1 was filled with 10 and then replaced with 20. 
nc.find(10); // Number 10 is at the indices 2, 3, and 5. The smallest index that is filled with 10 is 2. Therefore, we return 2.
 

Constraints:

1 <= index, number <= 10^9
At most 105 calls will be made in total to change and find.
*/

class NumberContainers {
private:
    unordered_map<int, int> indices;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> nums;

public:
    NumberContainers() {}

    void change(int index, int number) {
        indices[index] = number;
        nums[number].push(index);
    }

    int find(int number) {
        if (nums.find(number) == nums.end())
            return -1;

        while (!nums[number].empty()) {
            int ind = nums[number].top();

            if (indices[ind] == number)
                return ind;

            nums[number].pop();
        }
        return -1;
    }
};

/*
Time Complexity: O(log(n))
Space Complexity: O(n)
*/

/*
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

/*
class NumberContainers {
public:
   unordered_map<int, set<int>> mpp;
   unordered_map<int, int> check;

   NumberContainers() {}

   void change(int index, int number) {
       if (check.count(index)) {
           int prevNum = check[index];
           mpp[prevNum].erase(index);
           if (mpp[prevNum].empty()) {
               mpp.erase(prevNum);
           }
       }
       check[index] = number;
       mpp[number].insert(index);
   }

   int find(int number) {
       if (mpp.find(number) == mpp.end() || mpp[number].empty())
           return -1;
       return *mpp[number].begin();
   }
};

* Your NumberContainers object will be instantiated and called as such:
* NumberContainers* obj = new NumberContainers();
* obj->change(index,number);
* int param_2 = obj->find(number);
*/

/*
Time Complexity: O(log(n))
Space Complexity: O(n)
*/

int main()
{
    NumberContainers nc;
    cout << nc.find(10) << endl;
    nc.change(2, 10);
    nc.change(1, 10);
    nc.change(3, 10);
    nc.change(5, 10);
    cout << nc.find(10) << endl;
    nc.change(1, 20);
    cout << nc.find(10) << endl;
    return 0;
}
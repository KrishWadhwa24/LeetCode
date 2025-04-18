#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int lis(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> temp;

        for(int i = 0; i < n; i++)
        {
            if(temp.empty() || arr[i] > temp.back())
            {
                temp.push_back(arr[i]);
            }else
            {
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }
        return temp.size();
    }
};

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution obj;
    cout<<obj.lis(arr)<<endl;
    return 0;
}
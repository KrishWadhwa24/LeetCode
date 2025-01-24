#include<bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. Otherwise, return false.



For Example
'N' = 3, 'K' = 5, 'A' = [1, 2, 3].
Subset [2, 3] has sum equal to 'K'.
So our answer is True.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
4 13
4 3 5 2
Sample Output 1 :
No
Sample Input 2 :
5 14
4 2 5 6 7
Sample Output 2 :
Yes
Constraints :
1 <= 'N' <= 10^3
1 <= 'A[i]' <= 10^3
1 <= 'K' <= 10^3
Time Limit: 1 sec
*/

bool isSubsetPresent(int ind,int sum,int n, int k, vector<int> &a)
{
    if(ind==n)
    {
        if(sum==k)
        return true;
        else
        return false;
    }

    sum += a[ind];
    if(sum<=k)
    if(isSubsetPresent(ind+1,sum,n,k,a))
    return true;

    sum -= a[ind];
    if(isSubsetPresent(ind+1,sum,n,k,a))
    return true;

    return false;
}

bool isSubsetPresent(int n, int k, vector<int>& a) {
    return isSubsetPresent(0, 0, n, k, a);
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<(isSubsetPresent(n,k,a)?"Yes":"No");
    return 0;
}
/*
A. Line Trip
Time limit: 2 seconds
Memory limit: 256 MB

You are traveling along a straight road, which can be represented as a number line. You start at point 0 and need to travel to point x, then return to point 0.

You have a car that consumes 1 liter of fuel per unit distance traveled. At the beginning of the journey (at point 0), your car’s fuel tank is full.

There are n gas stations located at positions a₁, a₂, …, aₙ along the road. Whenever you arrive at a gas station, your car is fully refueled. However, you can only refuel at gas stations—there are no gas stations at points 0 and x.

Your task is to determine the minimum possible fuel tank capacity (in liters) that allows you to travel from 0 to x and back to 0 without running out of fuel.

Input
The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.

Each test case consists of two lines:

The first line contains two integers n and x (1 ≤ n ≤ 50, 2 ≤ x ≤ 100) — the number of gas stations and the target position x.
The second line contains n distinct integers a₁, a₂, …, aₙ (0 < a₁ < a₂ < ⋯ < aₙ < x) — the positions of the gas stations.
Output
For each test case, print a single integer — the minimum required fuel tank capacity that allows the journey to x and back to 0.

Example
Input
Copy
Edit
3
3 7
1 2 5
3 6
1 2 5
1 10
7
Output
Copy
Edit
4
3
7
Explanation
Test Case 1: (n = 3, x = 7, stations = [1, 2, 5])
A minimum tank capacity of 4 liters is sufficient to reach x = 7 and return.

Travel to 1 → 3 liters left → Refuel → 4 liters
Travel to 2 → 3 liters left → Refuel → 4 liters
Travel to 5 → 1 liter left → Refuel → 4 liters
Travel to 7 → 2 liters left
Travel back via the same route, refueling at stations 5, 2, and 1, ensures the car can return to 0.
Test Case 2: (n = 3, x = 6, stations = [1, 2, 5])
A minimum tank capacity of 3 liters is sufficient.

Test Case 3: (n = 1, x = 10, stations = [7])
A minimum tank capacity of 7 liters is required since the car must travel 7 units without refueling before reaching a station.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pp pop_back
#define vec vector

vector<int> sieve(int n) {
    vector<int> primes, is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) is_prime[j] = false;
        }
    return primes;
}
template <typename T> vector<T> readVector(int n) { vector<T> vec(n); for (int i = 0; i < n; i++) cin >> vec[i];
    return vec;
}

template <typename T> void print(const vector<T> &v) { for (auto &e : v) cout << e << " "; cout << endl; }
template <typename T> void matrix(const vector<vector<T>> &v) { for (auto &r : v) print(r); }

void run() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;

        vector<int> arr = readVector<int>(n);
        int ans = INT_MIN;
        arr.push_back(x);
        for(int i =0;i<=n;i++)
        {
            if(i==0)
            {
                int diff = arr[i];
                ans = max(ans,diff);
            }else if(i==n)
            {
                int diff = 2*(arr[i]-arr[i-1]);
                ans = max(ans,diff);
            }
            else
            {
                int diff = arr[i] - arr[i-1];
                ans = max(ans,diff);
            }
        }
        cout<<ans<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    run();
    return 0;
}
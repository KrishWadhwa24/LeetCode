#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> sieve(int n)
{
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return primes;
}

template <typename T>
void print(const vector<T> &v)
{
    for (const auto &elem : v)
    {
        cout << elem << " ";
    }
    cout << endl;
}
template <typename T>
void matrix(const vector<vector<T>> &v)
{
    for (const auto &row : v)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}

void precompute(vector<ll>& ans)
{
    for(int d=1;d<=9;d++)
    {
        ll num = d;
        while(num<=1e9)
        {
            ans.push_back(num);
            num = num*10+d;
        }
    }
    sort(ans.begin(),ans.end());
}

void run()
{
    ll t;
    cin>>t;
    vector<ll> ans;
    precompute(ans);
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<upper_bound(ans.begin(),ans.end(),n)-ans.begin()<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}
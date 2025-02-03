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
    int k =1;
    int i =1;
    while(k<=1000)
    {
        if(i%3==0 || i%10==3)
        {
            i++;
            continue;
        }
        else
        {
            ans[k] = i;
            k++;
        }
        i++;
    }
}

void run()
{
    ll t;
    cin>>t;
    vector<ll> ans(1001,0);
    precompute(ans);
    while(t--)
    {
        ll k;
        cin>>k;

        cout<<ans[k]<<"\n";
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
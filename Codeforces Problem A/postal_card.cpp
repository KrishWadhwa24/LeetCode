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


void run()
{
    ll n,m;
    cin>>n>>m;
    vector<string> str(n);
    unordered_set<string> s2;

    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    for(int i=0;i<m;i++)
    {
        string str2;
        cin>>str2;
        s2.insert(str2);
    }

    int cnt = 0;
    for(int i =0;i<n;i++)
    {
        string sub = str[i].substr(3);
        if(s2.find(sub) != s2.end())
        {
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}
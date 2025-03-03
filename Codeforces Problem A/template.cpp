#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pp pop_back
#define vec vector
#define str string


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

template <typename T> void print(const vector<T> &v) { for (auto &e : v) cout << e << " "; cout << endl; }
template <typename T> void matrix(const vector<vector<T>> &v) { for (auto &r : v) print(r); }

void run() {}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    run();
    return 0;
}
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
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sort(x) sort(all(x))
#define reverse(x) reverse(all(x))
#define print_macro(x) cout << x << endl;
#define printarr(a,n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define printvec(v) for(auto x : v) cout << x << " "; cout << endl;
#define printpair(v) for(auto x : v) cout << x.F << " " << x.S << endl;
#define printmap(m) for(auto x : m) cout << x.F << " " << x.S << endl;
#define printset(s) for(auto x : s) cout << x << " "; cout << endl;
#define SQ(a) (a)*(a)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define vec vector
#define str string

const int MOD = 1e9+7;
const int INF = 1e9;
const ll LLINF = 1e18;

int digitCount(int x) { if (x == 0) return 1; return floor(log10(x) + 1);}
template <typename T> void print(const vector<T> &v) { for (auto &e : v) cout << e << " "; cout << endl; }
template <typename T> void matrix(const vector<vector<T>> &v) { for (auto &r : v) print(r); }
long long fibonacci(int n) { double sqrt5 = sqrt(5);double phi = (1 + sqrt5) / 2;return round(pow(phi, n) / sqrt5);}

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



void run() {}

int main() {
    fast;
    run();
    return 0;
}
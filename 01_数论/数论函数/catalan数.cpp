// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define i128 __int128
#define i32 int32_t
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " : " << x << endl
#define sig cerr << "OK" << endl;
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
template <typename T>
T rd(T l, T r)
{
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<T> dist(l, r);
    return dist(rng);
}
template <typename T>
bool ckmax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}
template <typename T>
bool ckmin(T &a, T b)
{
    return b < a ? (a = b, true) : false;
}

const int N = 1e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

//https://oi-wiki.org/math/combinatorics/catalan/

//下标从0开始
int fact[N];
int inv_fact[N];
int pw(int a, int b)
{
    int ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            ans = (i128)ans * a % mod;
        }
        a = (i128)a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}
void init(int n, int mod)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv_fact[n] = pw(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
}
int C(int n, int k, int mod)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}
void solve() 
{
    int n;
    cin >> n;
    vector <int> dp(n + 1), fac(2 * n + 1, 1);
    for (int i = 1; i <= n; i++) dp[i] = (i * 4 - 2) * dp[i - 1] / (i + 1);
    dp[n] = C(2 * n, n, mod) * pw(n + 1, mod - 2) % mod;
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundus
    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 1000000000000000000LL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

template <typename T, size_t SIZE>
void fl(T (&arr)[SIZE], const T &val)
{
    fill(arr, arr + SIZE, val);
}
template <typename Container>
void fl(Container &container, const typename Container::value_type &val)
{
    fill(container.begin(), container.end(), val);
}

const int N = 2e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

/*阶乘处理到模数-1即可*/
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
void init(int n)
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
int C(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}
int lucas(int n, int k)
{
    if (k == 0)
    {
        return 1;
    }
    return C(n % mod, k % mod) * lucas(n / mod, k / mod) % mod;
}
void solve()
{
    int n, m;
    cin >> n >> m >> mod;
    init(mod - 1);
    cout << lucas(n + m, n) << endl;
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
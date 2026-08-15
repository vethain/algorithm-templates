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

const int N = 5e5 + 5;
const double eps = 1e-9;
int mod = 9901;

/*这里是多个等比数列的乘积求和*/
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
vector<pair<int, int>> f;
void ise(int n)
{
    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            int c = 0;
            while (n % p == 0)
            {
                n /= p;
                c++;
            }
            f.push_back({p, c});
        }
    }
    if (n > 1)
    {
        f.push_back({n, 1});
    }
}
int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int get_inv(int a, int mo)
{
    int x, y;
    int d = exgcd(a, mo, x, y);
    if (d != 1)
    {
        return -1;
    }
    return (x % mo + mo) % mo;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    ise(a);
    i128 sum = 1;
    for (auto xx : f)
    {
        int a1 = xx.first, a2 = xx.second;
        int inv = get_inv(a1 - 1, mod);
        if (inv < 0)
        {
            sum *= (a2 * b + 1) % mod;
        }
        else
        {
            sum *= ((((pw(a1, a2 * b + 1) - 1) % mod + mod) % mod * inv) % mod);
            sum %= mod;
        }
    }
    cout << (int)sum << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
#define gcd __gcd
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

const int N = 5e6 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

int factor[N], cnt = 0;
int pw(int a, int b, int n)
{
    int ans = 1;
    a %= n;
    while (b)
    {
        if (b & 1)
        {
            ans = (i128)ans * a % n;
        }
        a = (i128)a * a % n;
        b >>= 1;
    }
    return ans;
}

bool witness(int a, int n)
{
    int u = n - 1;
    int t = 0;
    while ((u & 1) == 0)
    {
        u = u >> 1, t++;
    }
    int x1, x2;
    x1 = pw(a, u, n);
    for (int i = 1; i <= t; i++)
    {
        x2 = pw(x1, 2, n);
        if (x2 == 1 && x1 != 1 && x1 != n - 1)
        {
            return true;
        }
        x1 = x2;
    }
    if (x1 != 1)
    {
        return true;
    }
    return false;
}

int miller_rabin(int n, int s)
{
    if (n < 2)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return 0;
    }
    for (int i = 0; i < s && i < n; i++)
    {
        int a = rand() % (n - 1) + 1;
        if (witness(a, n))
        {
            return 0;
        }
    }
    return 1;
}
int mul(int a, int b, int n)
{
    a %= n, b %= n;
    i128 res = 0;
    while (b)
    {
        if (b & 1)
        {
            res += a;
            res = res >= n ? res - n : res;
        }
        a <<= 1;
        a = a >= n ? a - n : a;
        b >>= 1;
    }
    return (int)res;
}
int pollard_rho(int n)
{
    if (n % 2 == 0)
    {
        return 2;
    }
    if (n % 3 == 0)
    {
        return 3;
    }
    static mt19937_64 rng(time(0));
    int x = 0, y = 0, c = rng() % (n - 1) + 1;
    int val = 1;
    for (int step = 1;; step <<= 1)
    {
        y = x;
        for (int i = 1; i <= step; ++i)
        {
            x = ((i128)x * x + c) % n;
            val = (i128)val * abs(x - y) % n;
            if (i % 127 == 0)
            {
                int d = gcd(val, n);
                if (d > 1)
                {
                    return d;
                }
            }
        }
        int d = gcd(val, n);
        if (d > 1)
        {
            return d;
        }
    }
}

void findfac(int n)
{
    if (miller_rabin(n, 5))
    {
        factor[cnt++] = n;
        return;
    }
    int p = n;
    while (p >= n)
    {
        p = pollard_rho(p);
    }
    findfac(p);
    findfac(n / p);
}
void solve()
{
    int n;
    cin >> n;
    cnt = 0;
    findfac(n);
    if (cnt == 1)
    {
        cout << "Prime" << endl;
        return;
    }
    sort(factor, factor + cnt);
    cout << factor[cnt - 1] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}
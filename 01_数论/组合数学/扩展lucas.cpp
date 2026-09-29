// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define i128 __int128
#define i32 int32_t
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3f3fLL
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

// 扩展 Lucas：C(n, m) mod P，P 不必是质数
int pw(int a, int b, int p)          // 注意模数是参数，不是全局 mod
{
    int ans = 1;
    a %= p;
    while (b)
    {
        if (b & 1)
        {
            ans = (i128)ans * a % p;
        }
        a = (i128)a * a % p;
        b >>= 1;
    }
    return ans % p;
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
int inv(int a, int p)                // 要求 gcd(a, p) == 1
{
    int x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}
// n! 去掉所有 p 因子后 mod pk，其中 pk = p^e
int fac(int n, int p, int pk)
{
    if (n == 0)
    {
        return 1;
    }
    int r = 1;
    for (int i = 1; i <= pk; i++)
    {
        if (i % p)
        {
            r = (i128)r * i % pk;
        }
    }
    r = pw(r, n / pk, pk);
    for (int i = 1; i <= n % pk; i++)
    {
        if (i % p)
        {
            r = (i128)r * i % pk;
        }
    }
    return (i128)r * fac(n / p, p, pk) % pk;
}
// n! 中 p 的指数（Legendre 公式）
int cntp(int n, int p)
{
    int c = 0;
    while (n)
    {
        n /= p;
        c += n;
    }
    return c;
}
// C(n, m) mod p^e
int C_pk(int n, int m, int p, int e)
{
    int pk = 1;
    for (int i = 1; i <= e; i++)
    {
        pk *= p;
    }
    int c = cntp(n, p) - cntp(m, p) - cntp(n - m, p);
    if (c >= e)
    {
        return 0;
    }
    int r = (i128)fac(n, p, pk) * inv(fac(m, p, pk), pk) % pk;
    r = (i128)r * inv(fac(n - m, p, pk), pk) % pk;
    return (i128)r * pw(p, c, pk) % pk;
}
// C(n, m) mod P
int exlucas(int n, int m, int P)
{
    if (P == 1 || m < 0 || m > n)
    {
        return 0;
    }
    int x = P, ans = 0, M = 1;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int e = 0, pk = 1;
            while (x % i == 0)
            {
                x /= i;
                e++;
                pk *= i;
            }
            int r = C_pk(n, m, i, e);
            int t = (i128)((r - ans) % pk + pk) % pk * inv(M % pk, pk) % pk;
            ans = (ans + (i128)M * t) % (M * pk);
            M *= pk;
        }
    }
    if (x > 1)
    {
        int r = C_pk(n, m, x, 1);
        int t = (i128)((r - ans) % x + x) % x * inv(M % x, x) % x;
        ans = (ans + (i128)M * t) % (M * x);
    }
    return ans % P;
}

void solve() 
{
    int n, m, p;
    cin >> n >> m >> p;
    cout << exlucas(n, m, p) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundus
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}
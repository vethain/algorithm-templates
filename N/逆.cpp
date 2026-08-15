#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ld long double
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

const int N = 3e7;
const double eps = 1e-9;
int mod = 1e9 + 7;

//*
//*递推求逆
//*
int inv[N];
void solve()
{
    int n, p;
    cin >> n >> p;
    inv[1] = 1;
    cout << 1 << endl;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (p - p / i) * inv[p % i] % p; //%p因为求最小正整数解
        cout << inv[i] << endl;
    }
}
//*
//*扩展欧几里得求逆
//*
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
    int x, y;
    int d = exgcd(a, b, x, y);
    mod = b;
    cout << (x % mod + mod) % mod << endl;
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
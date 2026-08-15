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

const int N = 5e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

/*前提  模数两两互质  即数组a里的数两两互质*/
i128 exgcd(i128 a, i128 b, i128 &x, i128 &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    i128 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
i128 get_inv(i128 a, i128 mo)
{
    i128 x, y;
    i128 d = exgcd(a, mo, x, y);
    return (x % mo + mo) % mo;
}
int get_x(vector<int> &a, vector<int> &b, int n)
{
    i128 x = 0;
    i128 nmod = 1;
    for (int i = 1; i <= n; i++)
    {
        nmod *= a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        i128 now = nmod / a[i];
        i128 inv = get_inv(now, a[i]);
        x += (i128)b[i] % nmod * now % nmod * (inv % nmod) % nmod;
        x %= nmod;
    }
    return (int)x;
}
/*a存模数！ b存余数！*/
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    cout << get_x(a, b, n) << endl;
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
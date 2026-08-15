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

/*试除法  O(sqrt(n))*/
bool isprime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

/*Miller-Rabin 测试   O(s*(log2 n)^3)*/
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
void solve()
{
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
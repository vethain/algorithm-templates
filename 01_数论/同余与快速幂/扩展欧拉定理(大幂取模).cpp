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
int mod = 1e9 + 7;
int bgmd(string &s, int mod)
{
    int res = 0;
    for (char c : s)
    {
        int digit = c - '0';
        res = (res * 10 + digit) % mod;
    }
    return res;
}
int euler(int n)
{
    int ans = n;
    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            ans = ans / p * (p - 1);
        }
        while (n % p == 0)
        {
            n /= p;
        }
    }
    if (n != 1)
    {
        ans = ans / n * (n - 1);
    }
    return ans;
}
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
void solve()
{
    int a;
    string b;
    cin >> a >> mod >> b;
    if (mod == 1)
    {
        cout << 0 << endl;
        return;
    }
    int sz = b.size();
    int phi = euler(mod);
    if (b.size() <= 18)
    {
        int nb = stoi(b);
        if (nb < phi)
        {
            cout << pw(a, nb) << endl;
            return;
        }
    }
    int m1 = bgmd(b, phi);
    int gd = gcd(a, mod);
    if (gd == 1)
    {
        cout << pw(a, m1) << endl;
    }
    else
    {
        m1 += phi;
        cout << pw(a, m1) << endl;
    }
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
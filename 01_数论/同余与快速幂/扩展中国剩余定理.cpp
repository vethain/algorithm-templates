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
int get_x(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    i128 m1 = a[0], y1 = b[0];
    y1 = (y1 % m1 + m1) % m1;
    for (int i = 1; i < n; i++)
    {
        i128 m2 = a[i], y2 = b[i], x, y, c = y2 - y1;
        i128 d = exgcd(m1, m2, x, y);
        i128 nx = x * c / d % (m2 / d);
        nx = nx * m1 + y1;
        m1 = m1 / d * m2;
        y1 = (nx % m1 + m1) % m1;
    }
    return (int)((y1 % m1 + m1) % m1);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    cout << get_x(a, b);
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
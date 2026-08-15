#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
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

const int mod = 1e9 + 7;
const int N = 2050;
const double eps = 1e-9;

int t1[N][N], t2[N][N], t3[N][N], t4[N][N];
int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int y, int d)
{
    for (int i = x; i < N; i += lowbit(i))
    {
        for (int j = y; j < N; j += lowbit(j))
        {
            t1[i][j] += d;
            t2[i][j] += x * d;
            t3[i][j] += y * d;
            t4[i][j] += x * y * d;
        }
    }
}
int sum(int x, int y)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
        {
            ans += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] - (x + 1) * t3[i][j] + t4[i][j];
        }
    }
    return ans;
}
void solve()
{
    char c;
    int m, n;
    cin >> c >> m >> n;
    while (cin >> c)
    {
        if (c == 'L')
        {
            int x1, y1, x2, y2, d;
            cin >> x1 >> y1 >> x2 >> y2 >> d;
            update(x1, y1, d);
            update(x1, y2 + 1, -d);
            update(x2 + 1, y1, -d);
            update(x2 + 1, y2 + 1, d);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int ans = sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
            cout << ans << endl;
        }
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
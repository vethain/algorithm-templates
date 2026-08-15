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
const int N = 5e5 + 5;
const double eps = 1e-9;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, -inf));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> f(n, vector<int>(m, -inf));
    vector<vector<int>> g(n, vector<int>(m, -inf));
    f[0][0] = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j - 1 >= 0)
            {
                f[i][j] = max(f[i][j - 1] + a[i][j], f[i][j]);
            }
            if (i - 1 >= 0)
            {
                f[i][j] = max(f[i - 1][j] + a[i][j], f[i][j]);
            }
        }
    }
    g[n - 1][m - 1] = a[n - 1][m - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i + 1 < n)
            {
                g[i][j] = max(g[i + 1][j] + a[i][j], g[i][j]);
            }
            if (j + 1 < m)
            {
                g[i][j] = max(g[i][j + 1] + a[i][j], g[i][j]);
            }
        }
    }
    vector<vector<int>> L(n, vector<int>(m, -inf));
    vector<vector<int>> R(n, vector<int>(m, -inf));
    // L[i][j] 当前在i j  下一步不走i j + 1的最大值
    // R[i][j] 当前在i j  上一步不在i j - 1的最大值
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            L[i][j] = f[i][j] + g[i + 1][j];
            if (j > 0)
            {
                L[i][j] = max(L[i][j], L[i][j - 1]);
            }
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            R[i][j] = f[i - 1][j] + g[i][j];
            if (j < m - 1)
            {
                R[i][j] = max(R[i][j], R[i][j + 1]);
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int now = f[i][j] + g[i][j] - 3 * a[i][j];
            if (j > 0)
            {
                now = max(now, L[i][j - 1]);
            }
            if (j < m - 1)
            {
                now = max(now, R[i][j + 1]);
            }
            ans = min(ans, now);
        }
    }
    cout << ans << endl;
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
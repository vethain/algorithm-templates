#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
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

int tri[12], num[60000][15], n, m, dist[15][15], ans, dp[60000][15];
void init()
{
    tri[0] = 0;
    tri[1] = 1;
    for (int i = 2; i < 12; i++)
    {
        tri[i] = tri[i - 1] * 3;
    }
    for (int i = 1; i < tri[11]; i++)
    {
        int now = i;
        for (int k = 1; k <= 10; k++)
        {
            num[i][k] = now % 3;
            now /= 3;
        }
    }
}
void get()
{
    memset(dp, inf, sizeof(dp));
    memset(dist, inf, sizeof(dist));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = min(w, dist[u][v]);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[tri[i]][i] = 0;
    }
    for (int i = 1; i < tri[n + 1]; i++)
    {
        bool ok = 1;
        for (int j = 1; j <= n; j++)
        {
            if (num[i][j] == 0)
            {
                ok = 0;
                continue;
            }
            for (int k = 1; k <= n; k++)
            {
                if (k != j && num[i][k])
                {
                    dp[i][j] = min(dp[i][j], dp[i - tri[j]][k] + dist[j][k]);
                }
            }
        }
        if (ok)
        {
            for (int j = 1; j <= n; j++)
            {
                ans = min(ans, dp[i][j]);
            }
        }
    }
}
void solve()
{
    while (cin >> n >> m)
    {
        ans = inf;
        get();
        cout << (ans == inf ? -1 : ans) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundus
    int _ = 1;
    // cin >> _;
    init();
    while (_--)
        solve();

    return 0;
}
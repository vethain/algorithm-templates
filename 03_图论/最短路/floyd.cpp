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

const int N = 505;
const double eps = 1e-9;
int mod = 1e9 + 7;

int dp[N][N], path[N][N], a[N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
    memset(dp, inf, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    /*初始化！！！！！！！！！！！！！！！！！！！！！！！！*/
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = min(dp[v][u], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int now = dp[i][k] + dp[k][j];
                if (now < dp[i][j])
                {
                    dp[i][j] = now;
                    path[i][j] = path[i][k];
                }
                else if (now == dp[i][j] && path[i][j] > path[i][k])
                {
                    path[i][j] = path[i][k];
                }
            }
        }
    }
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
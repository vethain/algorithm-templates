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

const int N = 1e2 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

int dp[N][N], sum[N];
vector<pair<int, int>> g[N];
void dfs(int u, int fa)
{
    for (auto [v, val] : g[u])
    {
        if (v == fa)
        {
            continue;
        }
        dfs(v, u);
        sum[u] += sum[v] + 1;
        for (int j = sum[u]; j >= 0; j--)
        {
            for (int k = 0; k < j; k++)
            {
                dp[u][j] = max(dp[u][j], dp[u][j - k - 1] + dp[v][k] + val);
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v, val;
        cin >> u >> v >> val;
        g[u].emplace_back(v, val);
        g[v].emplace_back(u, val);
    }
    dfs(1, 0);
    cout << dp[1][m] << endl;
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
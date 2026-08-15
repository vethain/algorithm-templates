#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
#define gcd __gcd
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

const int N = 2e4 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

vector<int> g[N], num(N), low(N), is(N);
int cnt = 0;
void dfs(int u, int fa, int rt)
{
    num[u] = low[u] = ++cnt;
    int child = 0;
    for (auto v : g[u])
    {
        if (!num[v])
        {
            child++;
            dfs(v, u, rt);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u] && u != rt)
            {
                is[u] = 1;
            }
        }
        else if (num[v] < num[u])
        {
            low[u] = min(num[v], low[u]);
        }
    }
    if (u == rt && child >= 2)
    {
        is[u] = 1;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
        {
            dfs(i, i, i);
        }
    }
    int cut = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (is[i])
        {
            cut++;
            ans.push_back(i);
        }
    }
    cout << cut << endl;
    for (auto xx : ans)
    {
        cout << xx << " ";
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
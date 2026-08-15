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

//多测所有的都得清空

vector<int> g[N];
int go[N][30], dep[N], mii[N][30];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    go[u][0] = fa;
    // mii[u][0] = w;
    for (int i = 1; (1 << i) <= dep[u]; i++)
    {
        go[u][i] = go[go[u][i - 1]][i - 1];
        // mii[u][i] = min(mii[u][i - 1], mii[go[u][i - 1]][i - 1]);
    }
    for (auto v : g[u])
    {
        if (v != fa)
        {
            dfs(v, u);
        }
    }
}
int LCA(int x, int y)
{
    // int themin = inf;
    if (dep[x] < dep[y])
    {
        swap(x, y);
    }
    for (int i = 29; i >= 0; i--)
    {
        if (dep[x] - (1 << i) >= dep[y])
        {
            // themin = min(themin, mii[x][i]);
            x = go[x][i];
        }
    }
    if (x == y)
    {
        // return themin;
        return x;
    }
    for (int i = 29; i >= 0; i--)
    {
        if (go[x][i] != go[y][i])
        {
            // themin = min(themin, mii[x][i]);
            // themin = min(themin, mii[y][i]);
            x = go[x][i];
            y = go[y][i];
        }
    }
    // themin = min(themin, mii[x][0]);
    // themin = min(themin, mii[y][0]);
    return go[x][0];BUS_ADRALN
}
void solve()
{
    int n, q, s;
    cin >> n >> q >> s;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[s] = 1;
    dfs(s, 0);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << LCA(x, y) << endl;
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
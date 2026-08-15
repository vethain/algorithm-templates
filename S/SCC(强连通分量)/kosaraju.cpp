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

const int N = 1e4 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

int cnt = 0, n, m;
vector<int> s, vis1(N), vis2(N), g[N], rg[N];
void dfs1(int u)
{
    vis1[u] = 1;
    for (auto v : g[u])
    {
        if (!vis1[v])
        {
            dfs1(v);
        }
    }
    s.push_back(u);
}
void dfs2(int u)
{
    vis2[u] = 1;
    for (auto v : rg[u])
    {
        if (!vis2[v])
        {
            dfs2(v);
        }
    }
}
void kosaraju()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis1[i])
        {
            dfs1(i);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (!vis2[s[i]])
        {
            cnt++;
            dfs2(s[i]);
        }
    }
}
void solve()
{
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        s.clear();
        fl(vis1, 0);
        fl(vis2, 0);
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
            rg[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        kosaraju();
        cout << (cnt == 1 ? "Yes" : "No") << endl;
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
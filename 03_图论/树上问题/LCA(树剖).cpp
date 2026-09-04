// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define i128 __int128
#define i32 int32_t
// #define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " : " << x << endl
#define sig cerr << "OK" << endl;
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
template <typename T>
T rd(T l, T r)
{
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<T> dist(l, r);
    return dist(rng);
}
template <typename T>
bool ckmax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}
template <typename T>
bool ckmin(T &a, T b)
{
    return b < a ? (a = b, true) : false;
}

const int N = 5e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

int n, q, s;
vector <int> g[N];
int dep[N], bson[N], fa[N], sz[N], rt[N];
void dfs1(int u, int pa)
{
    dep[u] = dep[pa] + 1;
    sz[u] = 1;
    fa[u] = pa;
    for (auto v : g[u])
    {
        if (v != pa)
        {
            dfs1(v, u);
            if (sz[v] > sz[bson[u]]) bson[u] = v;
            sz[u] += sz[v];
        }
    }
}
void dfs2(int u, int pa)
{
    rt[u] = pa;
    if (!bson[u]) return;
    dfs2(bson[u], pa);
    for (auto v : g[u])
    {
        if (v != fa[u] && v != bson[u])
            dfs2(v, v);
    }
}
int lca(int u, int v)
{
    while (rt[u] != rt[v])
    {
        if (dep[rt[u]] > dep[rt[v]]) u = fa[rt[u]];
        else v = fa[rt[v]];
    }
    return (dep[v] > dep[u] ? u : v);
}
void solve() 
{
    cin >> n >> q >> s;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(s, 0);
    dfs2(s, s);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
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
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define i128 __int128
#define i32 int32_t
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " : " << x << endl
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

const int N = 3e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

struct node
{
    int v, w;
};
vector<node> g[N];
int go[N][30], dep[N], mn[N], id[N], a[N], stk[N], vis[N], dp[N];
int sz, nid = 0, top;
void dfs(int u, int fa, int w)
{
    id[u] = ++nid;
    mn[u] = min(mn[fa], w);
    dep[u] = dep[fa] + 1;
    go[u][0] = fa;
    // mii[u][0] = w;
    for (int i = 1; (1 << i) <= dep[u]; i++)
    {
        go[u][i] = go[go[u][i - 1]][i - 1];
        // mii[u][i] = min(mii[u][i - 1], mii[go[u][i - 1]][i - 1]);
    }
    for (auto [v, w] : g[u])
    {
        if (v != fa)
        {
            dfs(v, u, w);
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
    return go[x][0];
}
/**/
void build()
{
    sort(a + 1, a + 1 + sz, [&](int x, int y){return id[x] < id[y];});
    stk[top = 1] = 1; g[1].clear();
    for (int i = 1; i <= sz; i++)
    {
        if (a[i] != 1)
        {
            int fa = LCA(a[i], stk[top]);
            if (fa != stk[top])
            {
                while (id[fa] < id[stk[top - 1]])
                    g[stk[top - 1]].push_back({stk[top--], 0});
                if (id[fa] > id[stk[top - 1]])
                    g[fa].clear(), g[fa].push_back({stk[top], 0}), stk[top] = fa;
                else 
                    g[stk[top - 1]].push_back({stk[top--], 0}); 

            }
            stk[++top] = a[i];
            g[a[i]].clear();
        }
    }
    for (int i = 1; i < top; i++) g[stk[i]].push_back({stk[i + 1], 0});
}
void get(int u)
{
    dp[u] = 0;
    for (auto [v, w] : g[u])
    {
        get(v);
        if (vis[v]) dp[u] += mn[v];
        else dp[u] += min(mn[v], dp[v]);
    }
}
void solve() 
{
    int n, q;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    mn[0] = inf;
    dfs(1, 0, inf);
    cin >> q;
    while (q--)
    {
        cin >> sz;
        for (int i = 1; i <= sz; i++) cin >> a[i], vis[a[i]] = 1;
        build();
        get(1);
        cout << dp[1] << endl;
        for (int i = 1; i <= sz; i++) vis[a[i]] = 0;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundus
    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}
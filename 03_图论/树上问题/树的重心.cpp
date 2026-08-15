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

const int N = 1e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

void solve() 
{
    int n;
    cin >> n;
    vector <vector <int>> g(n + 1);
    vector <int> sz(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <int> ok(n, 0);
    int mii = inf, pos = 0;
    function<void(int, int)> dfs = [&](int u, int fa)
    {
        sz[u] = 1;
        int now = 0;
        for (auto v : g[u])
        {
            if (v != fa)
            {
                dfs(v, u);
                sz[u] += sz[v];
                ckmax(now, sz[v]);
            }
        }
        ckmax(now, n - sz[u]);
        if (now < mii)
        {
            mii = now;
            pos = 0;
            ok[pos] = u;
        }
        else if (now == mii)
        {
            ok[++pos] = u;
        }
    };
    dfs(1, 0);
    if (pos)
    {

    }
    else
    {
        
    }
}

/*每个子树的重心*/
void solve() 
{
    int n, q;
    cin >> n >> q;
    vector <vector <int>> g(n + 1);
    vector <int> sz(n + 1, 0), pa(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        u = i; cin >> v;
        pa[u] = v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <int> ans(n + 1, 0), son(n + 1, 0);
    function<void(int, int)> dfs = [&](int u, int fa)
    {
        sz[u] = 1;
        int maa = 0;
        for (auto v : g[u])
        {
            if (v != fa)
            {
                dfs(v, u);
                if (maa < sz[v]) son[u] = v, maa = sz[v];
                sz[u] += sz[v];
            }
        }
        if (g[u].size() == 1 && u != 1) ans[u] = u;
        else
        {
            int now = ans[son[u]];
            while (sz[u] - sz[now] > sz[u] / 2) now = pa[now];
            ans[u] = now;
        }
    };
    dfs(1, 0);
    while (q--)
    {
        int u;
        cin >> u;
        cout << ans[u] << endl;
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
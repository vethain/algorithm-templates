// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define i128 __int128
#define i32 int32_t
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3fLL
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

const int N = 1e4 + 5;
const int NN = 1e7 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

vector <int> sz(N), vis(N), hav(NN), ans(N), q(N), d(N);
int n, m, cnt, nsz;
struct node
{
    int u, w;
};
vector <node> g[N];
int gt1(int u)
{
    int nd = 0;
    int mii = inf, pos = 0;
    function<void(int, int)> dfs = [&](int u, int fa)
    {
        sz[u] = 1;
        int now = 0;
        for (auto [v, w] : g[u])
        {
            if (v != fa && !vis[v])
            {
                dfs(v, u);
                sz[u] += sz[v];
                ckmax(now, sz[v]);
            }
        }
        ckmax(now, nsz - sz[u]);
        if (now < mii)
        {
            mii = now;
            pos = 0;
            nd = u;
        }
    };
    dfs(u, 0);
    return nd;
}
void gt2(int u, int fa, int dis)
{
    d[++cnt] = dis;
    for (auto [v, w] : g[u])
        if (!vis[v] && v != fa)
            gt2(v, u, dis + w);
}
void gt3(int st)
{
    vector <int> usd;
    for (auto [v, w] : g[st])
    {
        if (vis[v]) continue;
        cnt = 0;
        gt2(v, st, w);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= cnt; j++)
                if (q[i] >= d[j] && hav[q[i] - d[j]])
                    ans[i] += hav[q[i] - d[j]];
        for (int i = 1; i <= cnt; i++)
            if (d[i] < NN) hav[d[i]]++, usd.push_back(d[i]);
    }
    for (auto xx : usd) hav[xx] = 0;
}
void dfz(int st)
{
    nsz = (sz[st] == 0 ? n : sz[st]);
    int rt = gt1(st);
    vis[rt] = 1;
    gt1(rt);
    gt3(rt);
    for (auto [v, w] : g[rt])
        if (!vis[v]) dfz(v);
}
void solve() 
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    hav[0] = 1;
    for (int i = 1; i <= m; i++) cin >> q[i];
    dfz(1);
    for (int i = 1; i <= m; i++) cout << (ans[i] ? "AYE" : "NAY") << endl;
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
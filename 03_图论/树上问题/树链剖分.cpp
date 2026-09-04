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
int num = 0;
int dep[N], bson[N], fa[N], sz[N], rt[N], id[N];
int a[N << 4], tree[N << 4], tag[N << 4], mii[N], maa[N];
int ls(int p)
{
    return p << 1;
}
int rs(int p)
{
    return p << 1 | 1;
}
void addtag(int p, int pl, int pr, int d)
{
    tag[p] = (tag[p] + d) % mod;
    tree[p] = (tree[p] + (pr - pl + 1) * d % mod) % mod;
}
void psup(int p)
{
    tree[p] = (tree[ls(p)] + tree[rs(p)]) % mod;
}
void psdn(int p, int pl, int pr)
{
    if (tag[p])
    {
        int mid = (pl + pr) >> 1;
        addtag(ls(p), pl, mid, tag[p]);
        addtag(rs(p), mid + 1, pr, tag[p]);
        tag[p] = 0;
    }
}
void build(int p, int pl, int pr)
{
    if (pl == pr) 
    {
        tree[p] = a[pl];
        tag[p] = 0;
        return;
    }
    int mid = (pl + pr) >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    psup(p);
}
void update(int L, int R, int p, int pl, int pr, int d)
{
    if (pl >= L && pr <= R)
    {
        addtag(p, pl, pr, d);
        return;
    }
    psdn(p, pl, pr);
    int mid = (pl + pr) >> 1;
    if (L <= mid) update(L, R, ls(p), pl, mid, d);
    if (R >= mid + 1) update(L, R, rs(p), mid + 1, pr, d);
    psup(p);         
}
int query(int L, int R, int p, int pl, int pr)
{
    if (pl >= L && pr <= R) return tree[p];
    psdn(p, pl, pr);
    int sum = 0;
    int mid = (pl + pr) >> 1;
    if (L <= mid) sum = (sum + query(L, R, ls(p), pl, mid)) % mod;
    if (R >= mid + 1) sum = (sum + query(L, R, rs(p), mid + 1, pr)) % mod;
    return sum;
}
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
    id[u] = ++num;
    if (!bson[u]) return;
    dfs2(bson[u], pa);
    for (auto v : g[u])
    {
        if (v != fa[u] && v != bson[u])
            dfs2(v, v);
    }
}
void dfs3(int u, int pa)
{
    mii[u] = maa[u] = id[u];
    for (auto v : g[u])
    {
        if (v != pa)
        {
            dfs3(v, u);
            ckmin(mii[u], mii[v]);
            ckmax(maa[u], maa[v]);
        }
    }
}
void upd1(int u, int v, int d)
{
    while (rt[u] != rt[v])
    {
        if (dep[rt[u]] > dep[rt[v]])
        {
            update(id[rt[u]], id[u], 1, 1, n, d);
            u = fa[rt[u]];
        }
        else 
        {
            update(id[rt[v]], id[v], 1, 1, n, d);
            v = fa[rt[v]];
        }
    }
    if (id[u] > id[v]) swap(u, v);
    update(id[u], id[v], 1, 1, n, d);
}
void upd2(int u, int d)
{
    update(mii[u], maa[u], 1, 1, n, d);
}
int qry1(int u, int v)
{
    int sum = 0;
    while (rt[u] != rt[v])
    {
        if (dep[rt[u]] > dep[rt[v]])
        {
            sum = (sum + query(id[rt[u]], id[u], 1, 1, n)) % mod;
            u = fa[rt[u]];
        }
        else 
        {
            sum = (sum + query(id[rt[v]], id[v], 1, 1, n)) % mod;
            v = fa[rt[v]];
        }
    }
    if (id[u] > id[v]) swap(u, v);
    sum = (sum + query(id[u], id[v], 1, 1, n)) % mod;
    return sum;
}
int qry2(int u)
{
    return query(mii[u], maa[u], 1, 1, n);
}
void solve() 
{
    cin >> n >> q >> s >> mod;
    vector <int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(s, 0);
    dfs2(s, s);
    dfs3(s, 0);
    for (int i = 1; i <= n; i++) a[id[i]] = b[i] % mod;
    build(1, 1, num);
    while (q--)
    {
        int op, x, y, z;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> z;
            upd1(x, y, z);
        }
        else if (op == 2)
        {
            cin >> x >> y;
            cout << qry1(x, y) << endl;
        }
        else if (op == 3)
        {
            cin >> x >> z;
            upd2(x, z);
        }
        else
        {
            cin >> x;
            cout << qry2(x) << endl;
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
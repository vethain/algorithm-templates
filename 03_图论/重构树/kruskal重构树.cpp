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

const int N = 1e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

/*注意  此处建立的新图是有向图  所以LCA的根必须是确切地根*/
int s[N], val[N], cnt = 0;
vector <int> g[N];
struct edge
{
    int u, v, w;
} a[N];
int find_set(int x)
{
    if (x != s[x])
    {
        s[x] = find_set(s[x]);
    }
    return s[x];
}
void merge_set(int x, int y)
{
    int nx = find_set(x);
    int ny = find_set(y);
    if (nx != ny)
    {
        s[nx] = ny;
    }
}
int n, m, q, id;
void krt()
{
    sort(a + 1, a + 1 + m, [&](edge x, edge y){return x.w < y.w; });
    for (int i = 1; i <= 2 * n; i++) s[i] = i;
    for (int i = 1; i <= m; i++)
    {
        if (cnt == n - 1) break;
        int f1 = find_set(a[i].u);
        int f2 = find_set(a[i].v);
        if (f1 != f2)
        {
            int nf = ++id;
            g[nf].push_back(f1);
            g[nf].push_back(f2);
            merge_set(f1, nf);
            merge_set(f2, nf);
            val[nf] = a[i].w;
            cnt++;
        }
    }
}
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
    return go[x][0];
}
void solve()
{
    cin >> n >> m >> q;
    id = n;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    krt();
    dfs(id, 0);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << val[LCA(u, v)] << endl;
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
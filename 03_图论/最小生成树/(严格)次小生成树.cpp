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

int s[N], cnt = 0, ans = 0, vis[N];
struct edge
{
    int u, v, w, id;
} a[N];
struct nedge
{
    int v, w;
};
vector<nedge> g[N];
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
int n, m;
void kruskal()
{
    sort(a + 1, a + 1 + m, [&](edge x, edge y)
         { return x.w < y.w; });
    for (int i = 1; i <= n; i++)
    {
        s[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        if (cnt == n - 1)
        {
            break;
        }
        int f1 = find_set(a[i].u);
        int f2 = find_set(a[i].v);
        if (f1 != f2)
        {
            vis[a[i].id] = 1;
            ans += a[i].w;
            g[a[i].v].push_back({a[i].u, a[i].w});
            g[a[i].u].push_back({a[i].v, a[i].w});
            vis[a[i].id] = 1;
            merge_set(f1, f2);
            cnt++;
        }
    }
}
int go[N][30], dep[N], maa[N][30], secmaa[N][30];
void dfs(int u, int fa, int w)
{
    dep[u] = dep[fa] + 1;
    go[u][0] = fa;
    maa[u][0] = w;
    secmaa[u][0] = -1;
    for (int i = 1; (1 << i) <= dep[u]; i++)
    {
        go[u][i] = go[go[u][i - 1]][i - 1];
        maa[u][i] = max(maa[u][i - 1], maa[go[u][i - 1]][i - 1]);
        int v[4] = {maa[u][i - 1], maa[go[u][i - 1]][i - 1], secmaa[u][i - 1], secmaa[go[u][i - 1]][i - 1]};
        for (auto xx : v)
        {
            if (xx < maa[u][i] && xx > secmaa[u][i])
            {
                secmaa[u][i] = xx;
            }
        }
    }
    for (auto [v, w] : g[u])
    {
        if (v != fa)
        {
            dfs(v, u, w);
        }
    }
}
pair<int, int> LCA(int x, int y)
{
    int themax = -1, secmax = -1;
    const auto merge = [&](int x, int y)
    {
        int m1 = max(themax, x);
        int v[4] = {themax, x, y, secmax};
        for (auto xx : v)
        {
            if (xx < m1 && xx > secmax)
            {
                secmax = xx;
            }
        }
        themax = m1;
    };
    if (dep[x] < dep[y])
    {
        swap(x, y);
    }
    for (int i = 29; i >= 0; i--)
    {
        if (dep[x] - (1 << i) >= dep[y])
        {
            merge(maa[x][i], secmaa[x][i]);
            x = go[x][i];
        }
    }
    if (x == y)
    {
        return {themax, secmax};
    }
    for (int i = 29; i >= 0; i--)
    {
        if (go[x][i] != go[y][i])
        {
            merge(maa[x][i], secmaa[x][i]);
            merge(maa[y][i], secmaa[y][i]);
            x = go[x][i];
            y = go[y][i];
        }
    }
    merge(maa[x][0], secmaa[x][0]);
    merge(maa[y][0], secmaa[y][0]);
    return {themax, secmax};
    // return go[x][0];
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k < 30; k++)
        {
            secmaa[i][k] = -1;
        }
    }
    int pos = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u != v)
        {
            pos++;
            a[pos].u = u;
            a[pos].v = v;
            a[pos].w = w;
            a[pos].id = pos;
        }
    }
    m = pos;
    kruskal();
    dfs(1, 0, -1);
    int mii = inf;
    for (int i = 1; i <= m; i++)
    {
        if (!vis[a[i].id])
        {
            int now = a[i].w;
            auto [ma, sec] = LCA(a[i].u, a[i].v);
            if (now != ma)
            {
                mii = min(now - ma, mii);
            }
            else
            {
                if (sec != -1)
                {
                    mii = min(now - sec, mii);
                }
            }
            // mii = min(now - ma,mii);
        }
    }
    cout << ans + mii << endl;
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
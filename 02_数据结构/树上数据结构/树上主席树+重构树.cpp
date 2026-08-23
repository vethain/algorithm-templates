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

const int N = 1e6 + 5;
const int NN = 1e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;
/*P4197*/

int s[2 * NN], val[2 * NN], cnt = 0;
vector <i32> g[2 * NN];
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
int go[2 * NN][30], dep[2 * NN];
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
struct nd2
{
    int lid, rid;
};
int qz[NN], to[NN];
int fa[NN], b[NN], cut = 0;
int get(int u, int x)
{
    for (int i = 29; i >= 0; i--)
    {
        if (val[go[u][i]] <= x)
        {
            // themin = min(themin, mii[x][i]);
            u = go[u][i];
        }
    }
    return u;
}
struct node
{
    int ls, rs, sum;
} tree[NN << 5];
int update(int bf, int pl, int pr, int x)
{
    int rt = ++cut;
    tree[rt] = tree[bf];
    tree[rt].sum++;
    int mid = (pl + pr) >> 1;
    if (pl < pr)
    {
        if (x <= mid) tree[rt].ls = update(tree[bf].ls, pl, mid, x);
        else tree[rt].rs = update(tree[bf].rs, mid + 1, pr, x); 
    }
    return rt;
}
int qry(int t1, int t2, int pl, int pr, int x)
{
    if (pl == pr) return pl;
    int now = tree[tree[t2].ls].sum - tree[tree[t1].ls].sum;
    int mid = (pl + pr) >> 1;
    if (x <= now) return qry(tree[t1].ls, tree[t2].ls, pl, mid, x);
    else return qry(tree[t1].rs, tree[t2].rs, mid + 1, pr, x - now);
}
void solve()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {cin >> qz[i]; b[i] = qz[i];}
    for (int i = 1; i <= m; i++) cin >> a[i].u >> a[i].v >> a[i].w;
    id = n;
    krt();
    val[0] = inf;
    vector <nd2> ng(2 * n + 1);
    int nid = 0;
    function<void(int)> df1 = [&](int u)
    {
        if (g[u].size() == 0)
        {
            to[++nid] = u;
            ng[u].lid = ng[u].rid = nid;
            return;
        }
        ng[u].lid = inf, ng[u].rid = -inf;
        for (auto v : g[u])
        {
            df1(v);
            ckmin(ng[u].lid, ng[v].lid);
            ckmax(ng[u].rid, ng[v].rid);
        }
    };
    for (int i = 1; i <= id; i++) 
    {
        if (find_set(i) == i) 
        {
            dfs(i, 0);
            df1(i);
        }
    }
    sort(b + 1, b + 1 + n);
    int sz = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b + 1, b + 1 + sz, qz[to[i]]) - b;
        fa[i] = update(fa[i - 1], 1, sz, pos);
    }
    int pr = 0;
    while (q--)
    {
        int u, x, k;
        cin >> u >> x >> k;
        // u = (u ^ pr) % n + 1, x = x ^ pr, k = (k ^ pr) % n + 1;
        int nf = get(u, x), len = ng[nf].rid - ng[nf].lid + 1;
        if (len < k) cout << -1 << endl, pr = 0;
        else pr = b[qry(fa[ng[nf].lid - 1], fa[ng[nf].rid], 1, sz, len - k + 1)], cout << pr << endl;
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
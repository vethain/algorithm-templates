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

int n, q;
// tree: 当前最大值, htree: 历史最大值
// tag: 当前加法标记, htag: 历史最大加法标记
int a[N << 2], tree[N << 2], htree[N << 2], tag[N << 2], htag[N << 2];

int ls(int p)
{
    return p << 1;
}
int rs(int p)
{
    return p << 1 | 1;
}

// 核心：打标记与标记下传
void addtag(int p, int d, int hd)
{
    // 1. 更新历史最大值（利用 tree[p] 与 历史最大标记 hd 组合）
    ckmax(htree[p], tree[p] + hd);
    // 2. 更新当前最大值
    tree[p] += d;
    
    // 3. 更新历史最大标记
    ckmax(htag[p], tag[p] + hd);
    // 4. 更新当前标记
    tag[p] += d;
}

void psup(int p)
{
    tree[p] = max(tree[ls(p)], tree[rs(p)]);
    htree[p] = max(htree[ls(p)], htree[rs(p)]);
}

void psdn(int p, int pl, int pr)
{
    // 只要有当前标记或历史最大标记，就需要下传
    if (tag[p] || htag[p])
    {
        addtag(ls(p), tag[p], htag[p]);
        addtag(rs(p), tag[p], htag[p]);
        tag[p] = 0;
        htag[p] = 0;
    }
}

void build(int p, int pl, int pr)
{
    tag[p] = htag[p] = 0;
    if (pl == pr) 
    {
        tree[p] = htree[p] = a[pl];
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
        // 新增增量为 d，在当次操作中，历史最大增量也是 d
        addtag(p, d, d);
        return;
    }
    psdn(p, pl, pr);
    int mid = (pl + pr) >> 1;
    if (L <= mid) update(L, R, ls(p), pl, mid, d);
    if (R >= mid + 1) update(L, R, rs(p), mid + 1, pr, d);
    psup(p);         
}

// type = 1: 查询当前最大值；type = 2: 查询历史最大值
int query(int L, int R, int p, int pl, int pr, int type)
{
    if (pl >= L && pr <= R) return type == 1 ? tree[p] : htree[p];
    psdn(p, pl, pr);
    
    int res = -inf;
    int mid = (pl + pr) >> 1;
    if (L <= mid) ckmax(res, query(L, R, ls(p), pl, mid, type));
    if (R >= mid + 1) ckmax(res, query(L, R, rs(p), mid + 1, pr, type));
    
    return res;
}

void solve() 
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    while (q--)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            // 区间 [x, y] 加上 k
            cin >> x >> y >> k;
            update(x, y, 1, 1, n, k);
        }
        else if (op == 2)
        {
            // 查询区间 [x, y] 当前最大值
            cin >> x >> y;
            cout << query(x, y, 1, 1, n, 1) << "\n";
        }
        else if (op == 3)
        {
            // 查询区间 [x, y] 历史最大值
            cin >> x >> y;
            cout << query(x, y, 1, 1, n, 2) << "\n";
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
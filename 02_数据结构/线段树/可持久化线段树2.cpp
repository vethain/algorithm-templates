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
#define tos to_string
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

const int N = 2e6 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

i32 a[N], fa[N], cnt = 0, n, q;
struct node
{
    int ls, rs, val;
} tree[N << 5];
int build(int pl, int pr)
{
    int rt = ++cnt;
    if (pl == pr)
    {
        tree[rt].val = a[pl];
        return rt;
    }
    int mid = (pl + pr) >> 1;
    tree[rt].ls = build(pl, mid);
    tree[rt].rs = build(mid + 1, pr);
    return rt;
}
int update(int bf, int pl, int pr, int pos, int x)
{
    int rt = ++cnt;
    tree[rt] = tree[bf];
    if (pl == pr)
    {
        tree[rt].val = x;
        return rt;
    }
    int mid = (pl + pr) >> 1;
    if (pos <= mid) tree[rt].ls = update(tree[bf].ls, pl, mid, pos, x);
    else tree[rt].rs = update(tree[bf].rs, mid + 1, pr, pos, x); 
    return rt;
}
int qry(int t1, int pl, int pr, int pos)
{
    if (pl == pr) return tree[t1].val;
    int mid = (pl + pr) >> 1;
    if (pos <= mid) return qry(tree[t1].ls, pl, mid, pos);
    else return qry(tree[t1].rs, mid + 1, pr, pos);
}
void solve() 
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    fa[0] = build(1, n);
    int id = 0;
    int res = cnt;
    while (q--)
    {
        int v, op, p, c;
        cin >> v >> op;
        if (op == 1)
        {
            cin >> p >> c;
            fa[++id] = update(fa[v], 1, n, p, c);
        }
        else
        {
            cin >> p;
            int now = qry(fa[v], 1, n, p);
            fa[++id] = fa[v];
            cout << now << endl;
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
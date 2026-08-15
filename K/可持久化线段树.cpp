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

const int N = 2e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

int a[N], b[N], fa[N], cnt = 0, n, q;
struct node
{
    int ls, rs, sum;
} tree[N << 5];
int update(int bf, int pl, int pr, int x)
{
    int rt = ++cnt;
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
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int sz = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
        fa[i] = update(fa[i - 1], 1, sz, pos);
    }
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << b[qry(fa[l - 1], fa[r], 1, sz, k)] << endl;
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
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

i32 a[N], b[N], fa[N], cnt = 0, n, q;
int last[N];
struct node
{
    i32 ls, rs, sum;
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
int qry(int t1, int t2, int pl, int pr, int qr)
{
    if (tree[t2].sum - tree[t1].sum == 0) return 0;
    if (pr <= qr) return tree[t2].sum - tree[t1].sum;
    int mid = (pl + pr) >> 1;
    int ans = qry(tree[t1].ls, tree[t2].ls, pl, mid, qr);
    if (qr > mid) ans += qry(tree[t1].rs, tree[t2].rs, mid + 1, pr, qr);
    return ans;
}
int find(int pos, int k) 
{
    int p = pos - 1;
    int step = 1;
    while (p + step <= n) 
    {
        if (qry(fa[pos - 1], fa[p + step], 0, n, pos - 1) <= k) 
        {
            p += step;
            step <<= 1;
        } 
        else break; 
    }
    step >>= 1;
    while (step > 0) 
    {
        if (p + step <= n) 
            if (qry(fa[pos - 1], fa[p + step], 0, n, pos - 1) <= k) 
                p += step;
        step >>= 1;
    }
    return p;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int sz = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
        //pos = a[i];  no lisan
        int pre = last[pos];
        last[pos] = i;
        fa[i] = update(fa[i - 1], 0, n, pre);
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0, pos = 1;
        while (pos <= n)
        {
            pos = find(pos, i) + 1;
            cnt++;
        }
        cout << cnt << " ";
        if (cnt == 1)
        {
            for (int j = i + 1; j <= n; j++) cout << 1 << " ";
            return;
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
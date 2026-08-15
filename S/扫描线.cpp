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

const int N = 1e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;
/*面积井*/
int a[N << 2], tree[N << 4], v[N << 4];
int n, cnt = 1, ans = 0;
struct node
{
    int x1, x2, dep, val;
} b[N << 2];
int ls(int p) {return p << 1;}
int rs(int p) {return p << 1 | 1;}
int get(int x)
{
    return lower_bound(a + 1, a + 1 + cnt, x) - a;
}
void psup(int p, int pl, int pr)
{
    if (v[p]) tree[p] = a[pr + 1] - a[pl];
    else
    {
        if (pl == pr) tree[p] = 0;
        else tree[p] = tree[ls(p)] + tree[rs(p)];
    }
}
void add(int l, int r, int p, int pl, int pr, int d)
{
    if (pl >= l && pr <= r)
    {
        v[p] += d;
        psup(p, pl, pr);
        return;
    }
    int mid = (pl + pr) >> 1;
    if (l <= mid) add(l, r, ls(p), pl, mid, d);
    if (r >= mid + 1) add(l, r, rs(p), mid + 1, pr, d);
    psup(p, pl, pr);
}
void solve() 
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        b[i] = {x1, x2, y1, 1};
        b[i + n] = {x1, x2, y2, -1};
        a[i] = x1; a[i + n] = x2; 
    }
    sort(a + 1, a + 1 + 2 * n);
    sort(b + 1, b + 1 + 2 * n, [&](node x, node y)
    {return (x.dep == y.dep ? x.val > y.val : x.dep < y.dep);});
    for (int i = 2; i <= 2 * n; i++)
    {
        if (a[i] != a[cnt]) a[++cnt] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i > 1) ans += tree[1] * (b[i].dep - b[i - 1].dep);
        add(get(b[i].x1), get(b[i].x2) - 1, 1, 1, cnt - 1, b[i].val);
    }
    cout << ans << endl;
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

/*周长井*/
int a[N << 2], tree[N << 4], v[N << 4];
int n, cnt = 1, ans = 0;
struct node
{
    int x1, x2, dep, val;
} b[N << 2], c[N << 2];
int ls(int p) {return p << 1;}
int rs(int p) {return p << 1 | 1;}
int get(int x)
{
    return lower_bound(a + 1, a + 1 + cnt, x) - a;
}
void psup(int p, int pl, int pr)
{
    if (v[p]) tree[p] = a[pr + 1] - a[pl];
    else
    {
        if (pl == pr) tree[p] = 0;
        else tree[p] = tree[ls(p)] + tree[rs(p)];
    }
}
void add(int l, int r, int p, int pl, int pr, int d)
{
    if (pl >= l && pr <= r)
    {
        v[p] += d;
        psup(p, pl, pr);
        return;
    }
    int mid = (pl + pr) >> 1;
    if (l <= mid) add(l, r, ls(p), pl, mid, d);
    if (r >= mid + 1) add(l, r, rs(p), mid + 1, pr, d);
    psup(p, pl, pr);
}
void solve() 
{
    cin >> n;
    int pr = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i].x1 >> c[i].x2 >> c[i].dep >> c[i].val;
    }
    const auto cal = [&](int op)
    {
        memset(tree, 0, sizeof(tree));
        memset(v, 0, sizeof(v));
        cnt = 1;
        if (op == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                auto [x1, y1, x2, y2] = c[i];
                b[i] = {x1, x2, y1, 1};
                b[i + n] = {x1, x2, y2, -1};
                a[i] = x1; a[i + n] = x2; 
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                auto [y1, x1, y2, x2] = c[i];
                b[i] = {x1, x2, y1, 1};
                b[i + n] = {x1, x2, y2, -1};
                a[i] = x1; a[i + n] = x2; 
            }
        }
        sort(a + 1, a + 1 + 2 * n);
        sort(b + 1, b + 1 + 2 * n, [&](node x, node y)
        {return (x.dep == y.dep ? x.val > y.val : x.dep < y.dep);});
        for (int i = 2; i <= 2 * n; i++)
        {
            if (a[i] != a[cnt]) a[++cnt] = a[i];
        }
        pr = 0;
        for (int i = 1; i <= 2 * n; i++)
        {
            add(get(b[i].x1), get(b[i].x2) - 1, 1, 1, cnt - 1, b[i].val);
            int now = tree[1];
            ans += abs(pr - now);
            pr = now;
        }
    };
    cal(1); cal(0);
    cout << ans << endl;
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
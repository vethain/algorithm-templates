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
int mod = 571373;

int n, q;
int a[N << 4], tree[N << 4], tag[N << 4], tag2[N << 4], tag3[N << 4];
int ls(int p)
{
    return p << 1;
}
int rs(int p )
{
    return p << 1 | 1;
}
void addtag(int p, int pl, int pr, int d)
{
    tag[p] = (tag[p] + d) % mod;
    tree[p] = (tree[p] + (pr - pl + 1) * d % mod) % mod;
}
void addtag2(int p, int pl, int pr, int d)
{
    tag2[p] = (tag2[p] * d) % mod;
    tag[p] = d * tag[p] % mod;
    tree[p] = tree[p] * d % mod;
}
void addtag3(int p, int pl, int pr, int d)
{
    tag3[p] = d;
    tag2[p] = 1;
    tag[p] = 0;
    tree[p] = (pr - pl + 1) * d % mod;
}
void psup(int p)
{
    tree[p] = (tree[ls(p)] + tree[rs(p)]) % mod;
}
void psdn(int p, int pl, int pr)
{
    if (tag3[p] != inf)
    {
        int mid = (pl + pr) >> 1;
        addtag3(ls(p), pl, mid, tag3[p]);
        addtag3(rs(p), mid + 1, pr, tag3[p]);
        tag3[p] = inf;
    }
    if (tag2[p] != 1)
    {
        int mid = (pl + pr) >> 1;
        addtag2(ls(p), pl, mid, tag2[p]);
        addtag2(rs(p), mid + 1, pr, tag2[p]);
        tag2[p] = 1;
    }
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
    tag[p] = 0;
    tag2[p] = 1;
    tag3[p] = inf;
    if (pl == pr) 
    {
        tree[p] = a[pl];
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
void update2(int L, int R, int p, int pl, int pr, int d)
{
    if (pl >= L && pr <= R)
    {
        addtag2(p, pl, pr, d);
        return;
    }
    psdn(p, pl, pr);
    int mid = (pl + pr) >> 1;
    if (L <= mid) update2(L, R, ls(p), pl, mid, d);
    if (R >= mid + 1) update2(L, R, rs(p), mid + 1, pr, d);
    psup(p);         
}
void update3(int L, int R, int p, int pl, int pr, int d)
{
    if (pl >= L && pr <= R)
    {
        addtag3(p, pl, pr, d);
        return;
    }
    psdn(p, pl, pr);
    int mid = (pl + pr) >> 1;
    if (L <= mid) update3(L, R, ls(p), pl, mid, d);
    if (R >= mid + 1) update3(L, R, rs(p), mid + 1, pr, d);
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
void solve() 
{
    
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
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
int a[N << 4], tree[N << 4], tag[N << 4];
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
    tag[p] += d;
    tree[p] += (pr - pl + 1) * d;
}
void psup(int p)
{
    tree[p] = tree[ls(p)] + tree[rs(p)];
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
    if (L <= mid) sum += query(L, R, ls(p), pl, mid);
    if (R >= mid + 1) sum += query(L, R, rs(p), mid + 1, pr);
    return sum;
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
            cin >> x >> y >> k;
            update(x, y, 1, 1, n, k);
        }
        else
        {
            cin >> x >> y;
            cout << query(x, y, 1, 1, n) << endl;
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

// 注释版本
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <deque>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <iomanip>

#define endl '\n'
#define uul __int128 // 输入输出需自定义
#define int long long int
#define ull unsigned long long int
#define ld long double
#define np next_permutation
#define pq priority_queue
using namespace std;

const int mod = 1e9;
const int N = 1e5 + 5;

int a[N];         // 原始数据数组
int tree[N << 2]; // 线段树数组，开4倍空间
int tag[N << 2];  // 懒标记数组，开4倍空间

inline int ls(int n)
{
    return n << 1; // 左孩子索引：2*n
}
inline int rs(int n)
{
    return n << 1 | 1; // 右孩子索引：2*n+1
}
// ls,rs函数都在使得n变大！从父节点索引计算子节点索引

void push_up(int p)
{
    // 从子节点更新父节点：父节点值 = 左孩子值 + 右孩子值
    tree[p] = tree[ls(p)] + tree[rs(p)];
}

void build(int p, int pl, int pr)
{
    tag[p] = 0; // 初始化当前节点的懒标记为0

    // 到达叶子节点：区间长度为1
    if (pl == pr)
    {
        tree[p] = a[pl]; // 叶子节点直接存储原始数组值
        return;
    }

    // 递归建树：将当前区间二分
    int mid = (pl + pr) / 2;
    build(ls(p), pl, mid);     // 递归构建左子树 [pl, mid]
    build(rs(p), mid + 1, pr); // 递归构建右子树 [mid+1, pr]

    push_up(p); // 从叶节点往上传值，故放在递归调用之后
}

void add_tag(int p, int pl, int pr, int d)
{
    // 添加懒标记：标记当前区间需要整体加d
    tag[p] += d;
    // 更新当前节点值：区间和增加 (区间长度 * d)
    tree[p] += (pr - pl + 1) * d;
}

void push_down(int p, int pl, int pr)
{
    // 如果当前节点有未下传的标记
    if (tag[p])
    {
        int mid = (pl + pr) / 2;
        // 将标记下传给左孩子
        add_tag(ls(p), pl, mid, tag[p]);
        // 将标记下传给右孩子
        add_tag(rs(p), mid + 1, pr, tag[p]);
        tag[p] = 0; // 清空当前节点的标记（已经下传）
    }
}

void update(int L, int R, int p, int pl, int pr, int d)
{
    // 情况1：当前区间[pl,pr]完全包含在目标区间[L,R]内
    if (L <= pl && R >= pr)
    {
        // 直接给当前节点打标记，不需要继续递归
        // 因为整个区间都要加d，所以可以直接计算新值
        add_tag(p, pl, pr, d);
        return;
    }

    // 情况2：当前区间与目标区间部分重叠
    // 必须先下传标记，因为要访问子节点了
    push_down(p, pl, pr);

    int mid = (pl + pr) / 2;
    // 如果目标区间与左子树区间有重叠，递归更新左子树
    if (L <= mid)
    {
        update(L, R, ls(p), pl, mid, d);
    }
    // 如果目标区间与右子树区间有重叠，递归更新右子树
    if (R > mid)
    {
        update(L, R, rs(p), mid + 1, pr, d);
    }

    // 更新完子节点后，重新计算当前节点的值
    push_up(p);
}

int query(int L, int R, int p, int pl, int pr)
{
    // 情况1：当前区间完全包含在查询区间内
    if (pl >= L && R >= pr)
    {
        // 直接返回当前节点的值（已经包含了所有懒标记的影响）
        return tree[p];
    }

    // 情况2：当前区间与查询区间部分重叠
    // 必须先下传标记，确保子节点的值是最新的
    push_down(p, pl, pr);

    int sum = 0;
    int mid = (pl + pr) / 2;
    // 如果查询区间与左子树有重叠，递归查询左子树
    if (L <= mid)
    {
        sum += query(L, R, ls(p), pl, mid);
    }
    // 如果查询区间与右子树有重叠，递归查询右子树
    if (R > mid)
    {
        sum += query(L, R, rs(p), mid + 1, pr);
    }
    return sum;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n); // 从根节点(索引1)开始建树，区间[1,n]

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int l, r, d;
            cin >> l >> r >> d;
            update(l, r, 1, 1, n, d); // 区间更新
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 1, 1, n) << endl; // 区间查询
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
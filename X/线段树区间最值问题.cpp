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
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
using namespace std;

const int mod = 1e9;
const int N = 1e6 + 5;
int sum[N << 2], ma[N << 2], se[N << 2], num[N << 2], a[N];

inline int ls(int p)
{
    return p << 1;
}
inline int rs(int p)
{
    return p << 1 | 1;
}
void push_up(int p)
{
    sum[p] = sum[ls(p)] + sum[rs(p)];
    ma[p] = max(ma[ls(p)], ma[rs(p)]);
    if (ma[rs(p)] == ma[ls(p)])
    {
        se[p] = max(se[ls(p)], se[rs(p)]);
        num[p] = num[ls(p)] + num[rs(p)];
    }
    else
    {
        se[p] = max(min(ma[ls(p)], ma[rs(p)]), max(se[rs(p)], se[ls(p)]));
        num[p] = ma[ls(p)] > ma[rs(p)] ? num[ls(p)] : num[rs(p)];
    }
}
void build(int p, int pl, int pr)
{
    if (pl == pr)
    {
        sum[p] = a[pl];
        ma[p] = a[pl];
        se[p] = -1;
        num[p] = 1;
        return;
    }
    int mid = (pl + pr) / 2;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    push_up(p);
}
void add_tag(int p, int x)
{
    if (x >= ma[p])
    {
        return;
    }
    sum[p] -= num[p] * (ma[p] - x);
    ma[p] = x;
}
void push_down(int p)
{
    add_tag(ls(p), ma[p]);
    add_tag(rs(p), ma[p]);
}
void update(int L, int R, int p, int pl, int pr, int x)
{
    if (x >= ma[p])
    {
        return;
    }
    if (L <= pl && R >= pr && se[p] < x)
    {
        add_tag(p, x);
        return;
    }
    push_down(p);
    int mid = (pl + pr) / 2;
    if (L <= mid)
    {
        update(L, R, ls(p), pl, mid, x);
    }
    if (R > mid)
    {
        update(L, R, rs(p), mid + 1, pr, x);
    }
    push_up(p);
}
int queryMax(int L, int R, int p, int pl, int pr)
{
    if (pl >= L && R >= pr)
    {
        return ma[p];
    }
    push_down(p);
    int ans = 0;
    int mid = (pl + pr) / 2;
    if (L <= mid)
    {
        ans = max(ans, queryMax(L, R, ls(p), pl, mid));
    }
    if (R > mid)
    {
        ans = max(ans, queryMax(L, R, rs(p), mid + 1, pr));
    }
    return ans;
}
int querySum(int L, int R, int p, int pl, int pr)
{
    if (pl >= L && R >= pr)
    {
        return sum[p];
    }
    push_down(p);
    int ans = 0;
    int mid = (pl + pr) / 2;
    if (L <= mid)
    {
        ans += querySum(L, R, ls(p), pl, mid);
    }
    if (R > mid)
    {
        ans += querySum(L, R, rs(p), mid + 1, pr);
    }
    return ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--)
    {
        int tt, l, r;
        cin >> tt >> l >> r;
        if (tt == 0)
        {
            int x;
            cin >> x;
            update(l, r, 1, 1, n, x);
        }
        else if (tt == 1)
        {
            cout << queryMax(l, r, 1, 1, n) << endl;
        }
        else
        {
            cout << querySum(l, r, 1, 1, n) << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
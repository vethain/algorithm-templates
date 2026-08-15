#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
using namespace std;

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

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const double eps = 1e-9;
int n, q;
struct node
{
    int time = 0, val, id;
} P[N], a[N], b[N];
int tree[N];
int A[N], B[N], f[N], ans = 0;
void mgs(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mgs(l, mid);
    mgs(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (A[i] > A[j])
        {
            ans += (mid - i + 1);
            B[k++] = A[j++];
        }
        else
        {
            B[k++] = A[i++];
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= r)
    {
        B[k++] = A[j++];
    }
    for (int i = l; i <= r; i++)
    {
        A[i] = B[i];
    }
}
void update(int x, int d, vector<int> &kk)
{
    for (; x < N; x += x & -x)
    {
        tree[x] += d;
        kk.push_back(x);
    }
}
int sum(int x)
{
    int res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
void CDQ(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    CDQ(l, mid);
    CDQ(mid + 1, r);
    vector<int> kk;
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i].val > a[j].val)
        {
            f[a[j].id] += sum(a[j].id);
            b[k++] = a[j++];
        }
        else
        {
            update(a[i].id, 1, kk);
            b[k++] = a[i++];
        }
    }
    while (i <= mid)
    {
        update(a[i].id, 1, kk);
        b[k++] = a[i++];
    }
    while (j <= r)
    {
        f[a[j].id] += sum(a[j].id);
        b[k++] = a[j++];
    }
    for (int as = l; as <= r; as++)
    {
        a[as] = b[as];
    }
    for (auto xx : kk)
    {
        tree[xx] = 0;
    }
}
void CDQ1(int l, int r, int si)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    CDQ1(l, mid, si);
    CDQ1(mid + 1, r, si);
    vector<int> kk;
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i].val > a[j].val)
        {
            f[si - a[j].id + 1] += sum(a[j].id);
            b[k++] = a[j++];
        }
        else
        {
            update(a[i].id, 1, kk);
            b[k++] = a[i++];
        }
    }
    while (i <= mid)
    {
        update(a[i].id, 1, kk);
        b[k++] = a[i++];
    }
    while (j <= r)
    {
        f[si - a[j].id + 1] += sum(a[j].id);
        b[k++] = a[j++];
    }
    for (int as = l; as <= r; as++)
    {
        a[as] = b[as];
    }
    for (auto xx : kk)
    {
        tree[xx] = 0;
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> now(q + 1);
    map<int, int> mid1, mid2, m_id;
    for (int i = 1; i <= n; i++)
    {
        cin >> P[i].val;
        A[i] = P[i].val;
        P[i].id = i;
        m_id[P[i].val] = P[i].id;
    }
    mgs(1, n);
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        now[i] = x;
        P[m_id[x]].time = q - i + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i].id = P[i].id;
        a[i].time = P[i].time;
        a[i].val = n - P[i].val + 1;
        mid1[a[i].val] = a[i].id;
    }
    sort(a + 1, a + 1 + n, [&](const node &x, const node &y)
         { return x.time < y.time || (x.time == y.time && (x.val < y.val || (x.val == y.val && x.id < y.id))); });
    CDQ(1, n);

    for (int i = 1; i <= n; i++)
    {
        a[i].id = n - P[i].id + 1;
        a[i].time = P[i].time;
        a[i].val = P[i].val;
        mid1[a[i].val] = a[i].id;
    }
    sort(a + 1, a + 1 + n, [&](const node &x, const node &y)
         { return x.time < y.time || (x.time == y.time && (x.val < y.val || (x.val == y.val && x.id < y.id))); });
    CDQ1(1, n, n);
    for (int i = 1; i <= q; i++)
    {
        cout << ans << endl;
        ans -= f[m_id[now[i]]];
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}
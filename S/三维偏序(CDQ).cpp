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
const int N = 2e5 + 5;
const double eps = 1e-9;

int ans[N], tree[N], f[N], cnt[N];
map<tuple<int, int, int>, int> mp;
struct node
{
    int a, b, c, id;
} a[N], b[N];
int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int d, vector<int> &kk)
{
    while (x < N)
    {
        tree[x] += d;
        kk.push_back(x);
        x += lowbit(x);
    }
}
int sum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
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
    int i = l, j = mid + 1, k = l;
    vector<int> kk;
    while (i <= mid && j <= r)
    {
        if (a[i].b > a[j].b)
        {
            f[a[j].id] += sum(a[j].c);
            b[k++] = a[j++];
        }
        else
        {
            update(a[i].c, cnt[a[i].id], kk);
            b[k++] = a[i++];
        }
    }
    while (i <= mid)
    {
        update(a[i].c, cnt[a[i].id], kk);
        b[k++] = a[i++];
    }
    while (j <= r)
    {
        f[a[j].id] += sum(a[j].c);
        b[k++] = a[j++];
    }
    for (int ll = l; ll <= r; ll++)
    {
        a[ll] = b[ll];
    }
    for (auto xx : kk)
    {
        tree[xx] = 0;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].b >> a[i].c;
        mp[{a[i].a, a[i].b, a[i].c}]++;
    }
    sort(a + 1, a + n + 1, [&](const node &x, const node &y)
         { return x.a < y.a || (x.a == y.a && (x.b < y.b || (x.b == y.b && x.c < y.c))); });
    node *last = unique(a + 1, a + n + 1, [&](const node &x, const node &y)
                        { return x.a == y.a && x.b == y.b && x.c == y.c; });
    int nl = last - a - 1;
    for (int i = 1; i <= nl; i++)
    {
        a[i].id = i;
        cnt[i] = mp[{a[i].a, a[i].b, a[i].c}];
    }
    CDQ(1, nl);
    for (int i = 1; i <= nl; i++)
    {
        ans[f[i] + cnt[i] - 1] += cnt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
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
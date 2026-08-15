#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
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

const int N = 5e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

int ans[N], go[N][35], n, m;
struct node
{
    int l, r, id;
} a[N];
void init()
{
    int pos = 1;
    for (int i = 1; i <= n; i++)
    {
        while (a[pos].l <= a[i].r && pos <= n)
        {
            pos++;
        }
        go[i][0] = pos - 1;
    }
    for (int k = 1; k <= 30; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            go[i][k] = go[go[i][k - 1]][k - 1];
        }
    }
}
void get(int x)
{
    int cur = x, len = a[x].l + m, cnt = 1;
    for (int i = 30; i >= 0; i--)
    {
        int pos = go[cur][i];
        if (a[pos].r < len)
        {
            cur = pos;
            cnt += (1 << i);
        }
    }
    ans[a[x].id] = cnt + 1;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
        if (a[i].r < a[i].l)
        {
            a[i].r += m;
        }
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, [&](node x, node y)
         {
    if (x.l == y.l)
    {
        return x.r < y.r;
    }
    return x.l < y.l; });
    for (int i = 1; i <= n; i++)
    {
        a[i + n] = a[i];
        a[i + n].r += m;
        a[i + n].l += m;
    }
    n *= 2;
    init();
    n /= 2;
    for (int i = 1; i <= n; i++)
    {
        get(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
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
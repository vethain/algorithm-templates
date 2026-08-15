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

int s[N], cnt = 0, ans = 0;
struct edge
{
    int u, v, w;
} a[N];
int find_set(int x)
{
    if (x != s[x])
    {
        s[x] = find_set(s[x]);
    }
    return s[x];
}
void merge_set(int x, int y)
{
    int nx = find_set(x);
    int ny = find_set(y);
    if (nx != ny)
    {
        s[nx] = ny;
    }
}
int n, m;
bool kruskal()
{
    sort(a + 1, a + 1 + m, [&](edge x, edge y)
         { return x.w < y.w; });
    for (int i = 1; i <= n; i++)
    {
        s[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        if (cnt == n - 1)
        {
            break;
        }
        int f1 = find_set(a[i].u);
        int f2 = find_set(a[i].v);
        if (f1 != f2)
        {
            ans += a[i].w;
            merge_set(f1, f2);
            cnt++;
        }
    }
    return cnt == n - 1;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    if (kruskal())
    {
        cout << ans << endl;
    }
    else
    {
        cout << "orz" << endl;
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
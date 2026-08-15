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

int n, m, cnt = 0, s = 1, d[N], pr[N];
struct edge
{
    int u, v, w;
} a[2 * N];
void get_path(int t)
{
    if (s == t)
    {
        cout << s;
        return;
    }
    get_path(pr[t]);
    cout << " " << t;
}
void bellman()
{
    fl(d, inf);
    fl(pr, -1LL);
    d[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            int u = a[j].u, v = a[j].v, w = a[j].w;
            if (d[u] != inf && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pr[v] = u;
            }
        }
    }
    bool has_negative_cycle = false;
    for (int j = 0; j < cnt; j++)
    {
        int u = a[j].u, v = a[j].v, w = a[j].w;
        if (d[u] != inf && d[v] > d[u] + w)
        {
            has_negative_cycle = true;
            break;
        }
    }
}
void solve()
{
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> a[cnt].u >> a[cnt].v >> a[cnt].w;
            cnt++;
            a[cnt] = a[cnt - 1];
            swap(a[cnt].u, a[cnt].v);
            cnt++;
        }
        bellman();
        cout << d[n] << endl;
        if (d[n] != inf)
        {
            get_path(n);
            cout << endl;
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
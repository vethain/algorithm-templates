#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 1000000000000000000LL
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

const int N = 1e4 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

int low[N], num[N], stk[N], id[N], top = 0, cnt, n, m, res = 0;
struct node
{
    int id, w;
};
vector<int> g[N];
void dfs(int u)
{
    stk[top++] = u;
    low[u] = num[u] = ++cnt;
    for (auto v : g[u])
    {
        if (!num[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!id[v])
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u])
    {
        res++;
        while (1)
        {
            int tp = stk[--top];
            id[tp] = res;
            if (u == tp)
            {
                break;
            }
        }
    }
}
void tarjan()
{
    fl(low, 0LL);
    fl(num, 0LL);
    cnt = res = top = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
        {
            dfs(i);
        }
    }
}
void solve()
{
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        tarjan();
        cout << (res == 1 ? "Yes" : "No") << endl;
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
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

const int N = 1e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

// 有向图
int id[N], od[N], cur[N];
vector<int> g[N];
stack<int> s;
void dfs(int now)
{
    for (int &i = cur[now]; i < g[now].size();)
    {
        int nxt = g[now][i++];
        dfs(nxt);
    }
    s.push(now);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        id[v]++;
        od[u]++;
        g[u].push_back(v);
    }
    int cnt = 0, st = 1;
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
        if (id[i] != od[i])
        {
            cnt++;
            if (od[i] - id[i] == 1)
            {
                st = i;
            }
            else if (id[i] - od[i] != 1)
            {
                ok = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (id[i] != od[i])
        {
            cnt++;
            if (od[i] - id[i] == 1)
            {
                st = i;
            }
            else if (id[i] - od[i] != 1)
            {
                ok = 0;
            }
        }
    }
    if ((cnt != 0 && cnt != 2) || !ok)
    {
        cout << "No" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(all(g[i]));
    }
    fl(cur, 0LL);
    dfs(st);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

// 无向图
int du[N], cur[N];
vector<pair<int, int>> g[N];
vector<bool> vis(N, 0);
stack<int> s;
void dfs(int now)
{
    for (int &i = cur[now]; i < g[now].size();)
    {
        int nxt = g[now][i].first;
        int idx = g[now][i].second;
        if (vis[idx])
        {
            i++;
            continue;
        }
        vis[idx] = 1;
        i++;
        dfs(nxt);
    }
    s.push(now);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        du[i] = 0;
    }
    fl(vis, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        du[u]++;
        du[v]++;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    int cnt = 0, st = -1;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] % 2 != 0)
        {
            cnt++;
            st = (st == -1 ? i : st);
        }
    }
    st = (st == -1 ? 1 : st);
    if (cnt != 0 && cnt != 2)
    {
        cout << "No" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(all(g[i]));
    }
    fl(cur, 0LL);
    dfs(st);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
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
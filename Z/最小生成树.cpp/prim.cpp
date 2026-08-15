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

struct edge
{
    int v, w;
};
vector<edge> g[N];
struct node
{
    int id, dis;
    bool operator<(node x) const
    {
        return dis > x.dis;
    }
};
int n, m, vis[N], ans = 0;
bool prim()
{
    int s = 1;
    fl(vis, 0LL);
    priority_queue<node> pq;
    pq.push({s, 0});
    int cnt = 0;
    while (!pq.empty())
    {
        auto [id, dis] = pq.top();
        pq.pop();
        if (vis[id])
        {
            continue;
        }
        vis[id] = 1;
        ans += dis;
        cnt++;
        for (auto [v, w] : g[id])
        {
            if (vis[v])
            {
                continue;
            }
            pq.push({v, w});
        }
    }
    return cnt == n;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    if (prim())
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
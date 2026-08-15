#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf -1000000000000000000LL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
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

int head[N], cnt = 0, dist[N], vis[N];
struct Edge
{
    int to;
    int next;
    int val;
} edge[N];
struct node
{
    int dis;
    int pos;
    bool operator<(const node &x) const
    {
        return x.dis < dis;
    }
};
void add_edge(int u, int v, int x)
{
    edge[cnt].to = v;
    edge[cnt].val = x;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void solve()
{
    fl(head, -1LL);
    fl(dist, -inf);
    fl(vis, 0LL);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    priority_queue<node> q;
    q.push({0, s});
    dist[s] = 0;
    auto djk = [&]() -> void
    {
        q.push({0, s});
        while (!q.empty())
        {
            node now = q.top();
            int nd = now.dis;
            int np = now.pos;
            q.pop();
            if (vis[np])
            {
                continue;
            }
            vis[np] = 1;
            for (int i = head[np]; i != -1; i = edge[i].next)
            {
                int val = edge[i].val;
                int pp = edge[i].to;
                if (dist[pp] > dist[np] + val)
                {
                    dist[pp] = dist[np] + val;
                }
                if (!vis[pp])
                {
                    q.push({dist[pp], pp});
                }
            }
        }
    };
    djk();
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
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
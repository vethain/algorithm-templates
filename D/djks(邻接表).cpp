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
const int N = 5e5 + 5;
int dist[N], vis[N];
vector<vector<pair<int, int>>> g(N);
struct node
{
    int val;
    int id;
    bool operator<(const node &x) const
    {
        return x.val < val;
    }
};
void solve()
{
    fl(dist, -inf);
    fl(vis, 0LL);
    int n, m, s;
    cin >> n >> m >> s;
    dist[s] = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    priority_queue<node> q;
    q.push({0, s});
    while (!q.empty())
    {
        node now = q.top();
        int ni = now.id;
        int nv = now.val;
        q.pop();
        if (vis[ni])
        {
            continue;
        }
        vis[ni] = 1;
        for (auto xx : g[ni])
        {
            int xi = xx.first;
            int xv = xx.second;
            if (dist[xi] > dist[ni] + xv)
            {
                dist[xi] = dist[ni] + xv;
                if (!vis[xi])
                {
                    q.push({dist[xi], xi});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != -inf)
        {
            cout << dist[i] << " ";
        }
        else
        {
            cout << (1 << 31) - 1 << " ";
        }
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
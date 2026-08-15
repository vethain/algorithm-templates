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

const int N = 1e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;
//普通  奇偶

struct edge
{
    int u, w;
};
struct node
{
    int dis, u;
    bool operator>(const node &b) const
    {
        return dis > b.dis;
    }
};
vector<edge> g[N];
int dist[N], dp[N];
void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    fl(dist, inf);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w}); // 无向图需建双边
    }
    // dp[s] = 1;
    const auto dijks = [&]()
    {
        priority_queue<node, vector<node>, greater<node>> pq;
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty())
        {
            auto [dis, u] = pq.top();
            pq.pop();
            if (dis > dist[u])
            {
                continue;
            }
            for (auto [v, w] : g[u])
            {
                if (dist[v] > dis + w)
                {
                    pq.push({dis + w, v});
                    dist[v] = dis + w;
                    // dp[v] = dp[u];
                }
                // else if (dist[v] == dis + w)
                // {
                //     dp[v] = (dp[u] + dp[v]) % mod;
                // }
            }
        }
    };
    dijks();
    for (int i = 1; i <= n; i++)
    {
        cout << (dist[i] == inf ? (1LL << 31) - 1 : dist[i]) << " ";
    }
}

//奇偶最短路
struct edge 
{
    int v, w; 
};
struct node 
{
    int dis, u, p;
    bool operator>(const node &b) const
    {
        return dis > b.dis;
    }
};
 
vector<int> g[N];
int dist[N][2];
 
void solve() 
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> ok(n + 1, 0);
    for (int i = 1; i <= n; i++) 
    {
        g[i].clear();
        dist[i][0] = dist[i][1] = inf;
    }
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;
        if (u == v) ok[u] = 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<pair<int, int>> q; 
    dist[1][0] = 0;
    q.push({1, 0});
    while (!q.empty()) 
    {
        auto [u, p] = q.front();
        q.pop();
        int dis = dist[u][p];
        for (int v : g[u]) 
        {
            int np = p ^ 1;
            if (dist[v][np] > dis + 1) 
            {
                dist[v][np] = dis + 1;
                q.push({v, np});
            }
        }
    }
}
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

int n, m, s = 1;
int d[N], pr[N];
bool inq[N];
int cnt[N];

struct edge
{
    int v, w;
};
vector<edge> adj[N];

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
bool SPFA()
{
    fill(d, d + n + 1, inf); //-inf
    fill(inq, inq + n + 1, false);
    fill(cnt, cnt + n + 1, 0LL);
    d[s] = 0;
    deque<int> q;
    q.push_back(s);
    inq[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        inq[u] = false;
        for (auto &e : adj[u])
        {
            int v = e.v, w = e.w;
            if (d[u] != inf && d[v] > d[u] + w) //-inf  <
            {
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n + 1)
                {
                    return true;
                }
                if (!inq[v])
                {
                    if (!q.empty() && d[v] < d[q.front()]) //>
                    {
                        q.push_front(v);
                    }
                    else
                    {
                        q.push_back(v);
                    }
                    inq[v] = true;
                }
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    {
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if (w >= 0)
            {
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
            else
            {
                adj[u].push_back({v, w});
            }
        }
    }
    if (SPFA())
    {
        Y;
    }
    else
    {
        O;
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
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
/*可用于判断负环*/
bool SPFA()
{
    fl(d, inf);
    fl(inq, false);
    fl(cnt, 0LL);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    inq[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (auto &e : adj[u])
        {
            int v = e.v, w = e.w;
            if (d[u] != inf && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n + 1) // 如果有0得是n + 1
                {
                    return true;
                }
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    return false;
}
/*SLF优化  不可判断负环*/
// bool SPFA()
// {
//     fl(d, inf);
//     fl(pr, -1LL);
//     fl(inq, false);
//     fl(cnt, 0LL);
//     d[s] = 0;
//     deque<int> q;
//     q.push_back(s);
//     inq[s] = true;
//     cnt[s] = 1;
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop_front();
//         inq[u] = false;

//         for (auto &e : adj[u])
//         {
//             int v = e.v, w = e.w;
//             if (d[u] != inf && d[v] > d[u] + w)
//             {
//                 d[v] = d[u] + w;
//                 pr[v] = u;

//                 if (!inq[v])
//                 {
//                     if (!q.empty() && d[v] < d[q.front()])
//                     {
//                         q.push_front(v);
//                     }
//                     else
//                     {
//                         q.push_back(v);
//                     }
//                     inq[v] = true;
//                     cnt[v]++;
//                     if (cnt[v] >= n)
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }

void solve()
{
    s = 0;
    cin >> n >> m;
    {
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            adj[0].push_back({i, 0});
        }
        for (int i = 0; i < m; i++)
        {
            int id, u, v, w;
            cin >> id >> u >> v;
            if (id == 1)
            {
                cin >> w;
                adj[u].push_back({v, -w});
            }
            else if (id == 2)
            {
                cin >> w;
                adj[v].push_back({u, w});
            }
            else
            {
                adj[u].push_back({v, 0});
                adj[v].push_back({u, 0});
            }
        }
    }
    if (SPFA())
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
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
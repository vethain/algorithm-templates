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
const int N = 4e6 + 5;

int head[N], cnt = 0;
struct Edge
{
    int to;
    int next;
    int val;
} edge[N];

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
    int n, m, fg;
    cin >> n >> m >> fg;
    if (fg == 1)
    {
        for (int i = 0; i < m; i++)
        {
            int u, v, val;
            cin >> u >> v >> val;
            add_edge(u, v, val);
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            int u, v, val;
            cin >> u >> v >> val;
            add_edge(u, v, val);
            add_edge(v, u, val);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = head[i]; j != -1; j = edge[j].next)
        {
            cout << i << " " << edge[j].to << " " << edge[j].val << endl;
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
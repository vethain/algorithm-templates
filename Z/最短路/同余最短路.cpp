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

int dist[N];
struct node
{
    int dis, v;
    bool operator<(node x) const
    {
        return dis > x.dis;
    }
};
struct edge
{
    int u, w;
};
vector<edge> g[N];
int n;
int get(int h, vector<int> a)
{
    for (int i = 0; i < a[0]; i++)
    {
        g[i].clear();
    }
    h--; // 注意从什么时候开始  再判断是否--
    fl(dist, inf);
    int s = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < a[0]; j++)
        {
            g[j].push_back({(j + a[i]) % a[0], a[i]});
        }
    }
    const auto dijks = [&]()
    {
        priority_queue<node> pq;
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
    int ans = 0;
    for (int i = 0; i < a[0]; i++)
    {
        ans += (h >= dist[i] ? (h - dist[i]) / a[0] + 1 : 0);
    }
    return ans;
}
void solve()
{
    int l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    cout << get(r, a) - get(l - 1, a) + 1 << endl;
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
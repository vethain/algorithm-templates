// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define i128 __int128
#define i32 int32_t
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " : " << x << endl
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
template <typename T>
T rd(T l, T r)
{
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<T> dist(l, r);
    return dist(rng);
}
template <typename T>
bool ckmax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}
template <typename T>
bool ckmin(T &a, T b)
{
    return b < a ? (a = b, true) : false;
}

const int N = 1e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

vector <int> g[N];
vector <int> msk;
int sum[N];
void dfs(int u, int fa)
{
    for (auto v : g[u])
    {
        if(v != fa)
        {
            dfs(v, u);
            sum[u] ^= sum[v];
        }
    }
    if (sum[u]) msk.push_back(sum[u]);
}
void solve() 
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear(), sum[i] = 0;
    msk.clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        sum[u] |= (1ll << i);
        sum[v] |= (1ll << i);
    }
    dfs(1, 0);
    sort(all(msk));
    msk.erase(unique(all(msk)), msk.end());
    int sz = msk.size();
    vector <int> dp((1ll << m), inf);
    dp[0] = 0;
    for (int mask = 0; mask < (1ll << m); mask++)
    {
        if (dp[mask] == inf) continue;
        for (int j = 0; j < sz; j++)
        {
            if ((mask & (msk[j])) == msk[j]) continue;
            ckmin(dp[mask | msk[j]], dp[mask] + 1);
        }
    }
    cout << dp[(1ll << m) - 1] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundus
    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
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
const int N = 2e3 + 5;
const double eps = 1e-9;
int ok[N], cnt[N], dp[15][105][2005];
void solve()
{
    int n, k;
    cin >> n >> k;
    int now = 0;
    for (int x = 0; x < (1 << n); x++)
    {
        int i = x;
        int ct = 0;
        while (i)
        {
            if (i & 1)
            {
                ct++;
            }
            i >>= 1;
        }
        if ((((x << 1) | (x >> 1)) & x) == 0)
        {
            cnt[x] = ct;
            ok[++now] = x;
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= now; j++)
        {
            int ns = ok[j];
            for (int xx = 1; xx <= now; xx++)
            {
                int nx = ok[xx];
                if ((((ns << 1) | ns | (ns >> 1)) & nx) == 0)
                {
                    for (int yy = 0; yy <= k; yy++)
                    {
                        if (yy - cnt[ns] >= 0)
                        {
                            dp[i][yy][ns] += dp[i - 1][yy - cnt[ns]][nx];
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= now; i++)
    {
        ans += dp[n][k][ok[i]];
    }
    cout << ans << endl;
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
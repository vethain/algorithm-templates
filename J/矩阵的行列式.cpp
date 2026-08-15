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

int mod = 1e9 + 7;
const int N = 605;
const double eps = 1e-9;
int n, a[N][N];
int cal()
{
    int res = 1, w = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            while (a[i][i])
            {
                int div = a[j][i] / a[i][i];
                for (int k = i; k <= n; k++)
                {
                    a[j][k] = (a[j][k] - 1ll * div * a[i][k] % mod + mod) % mod;
                }
                swap(a[i], a[j]);
                w = -w;
            }
            swap(a[i], a[j]);
            w = -w;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        res = a[i][i] * res % mod;
    }
    res = w * res;
    return (res + mod) % mod;
}
void solve()
{
    cin >> n >> mod;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = cal();
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
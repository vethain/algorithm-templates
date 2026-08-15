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
#define rall(x) x.rbegin(), x.rend()
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
const double eps = 1e-9;

int prm[5800000];
bool vis[N];
int E_sieve(int n)
{
    fl(vis, false);
    for (int i = 2; i * i <= n; i++)
    {
        if (!vis[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                vis[j] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prm[cnt++] = i;
        }
    }
    return cnt;
}
/*prm存筛出来的素数*/

void solve()
{
    int n;
    cin >> n;
    int k = E_sieve(n);
    for (int i = 0; i < k; i++)
    {
        cout << prm[i] << " ";
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
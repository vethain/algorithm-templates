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
const int N = 1e6 + 5;
const double eps = 1e-9;

int prm[5800000];
int vis[N];
int el_sieve(int n)
{
    int cnt = 0;
    fl(prm, 0LL);
    fl(vis, 0LL);
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prm[cnt++] = i;
            vis[i] = i;
        }
        for (int j = 0; j < cnt; j++)
        {
            if (i * prm[j] > n)
            {
                break;
            }
            vis[i * prm[j]] = prm[j];
            if (i % prm[j] == 0)
            {
                break;
            }
        }
    }
    return cnt;
}
void solve()
{
    int n;
    cin >> n;
    int k = el_sieve(n);
    for (int i = 2; i <= n; i++)
    {
        cout << vis[i] << endl;
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
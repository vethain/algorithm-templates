#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
#define gcd __gcd
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

const int N = 5e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

bool vis[N];
int prime[N], pr[N];
int Mob[N];
void Mobius_sieve()
{
    int cnt = 0;
    vis[1] = 1;
    Mob[1] = 1;
    pr[0] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
        {
            prime[cnt++] = i, Mob[i] = -1;
        }
        for (int j = 0; j < cnt && prime[j] * i <= N; j++)
        {
            vis[prime[j] * i] = 1;
            Mob[i * prime[j]] = (i % prime[j] ? -Mob[i] : 0);
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    for (int i = 1; i < N; i++)
    {
        pr[i] = pr[i - 1] + Mob[i];
    }
}
void solve()
{
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
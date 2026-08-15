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

/*单个求解  O(sqrt(n))*/
int euler(int n)
{
    int ans = n;
    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            ans = ans / p * (p - 1);
        }
        while (n % p == 0)
        {
            n /= p;
        }
    }
    if (n != 1)
    {
        ans = ans / n * (n - 1);
    }
    return ans;
}

/*1 ~ n 全部求解  O(n)*/
/*返回质数个数*/
int prm[5800000];
int vis[N], phi[N];
int get_phi(int n)
{
    int cnt = 0;
    fl(prm, 0LL);
    fl(vis, 0LL);
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            phi[i] = i - 1;
            prm[cnt++] = i;
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
                phi[i * prm[j]] = phi[i] * prm[j];
                break;
            }
            phi[i * prm[j]] = phi[i] * phi[prm[j]];
        }
    }
    return cnt;
}
void solve()
{
    int n;
    cin >> n;
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
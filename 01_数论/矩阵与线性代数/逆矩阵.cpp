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
const int N = 1e6 + 5;
const double eps = 1e-9;

int pw(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

bool gauss_inv(vector<vector<int>> &a, int n, vector<vector<int>> &ans)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans[i][j] = (i == j) ? 1 : 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {

        int pivot = i;
        while (pivot <= n && a[pivot][i] == 0)
            pivot++;
        if (pivot > n)
            return false;
        if (pivot != i)
        {
            swap(a[i], a[pivot]);
            swap(ans[i], ans[pivot]);
        }
        int inv_pivot = pw(a[i][i], mod - 2);
        for (int j = i; j <= n; j++)
        {
            a[i][j] = 1ll * a[i][j] * inv_pivot % mod;
        }
        for (int j = 1; j <= n; j++)
        {
            ans[i][j] = 1ll * ans[i][j] * inv_pivot % mod;
        }
        for (int j = 1; j <= n; j++)
        {
            if (j != i && a[j][i] != 0)
            {
                int coef = a[j][i];
                for (int k = i; k <= n; k++)
                {
                    a[j][k] = (a[j][k] - coef * a[i][k] % mod + mod) % mod;
                }
                for (int k = 1; k <= n; k++)
                {
                    ans[j][k] = (ans[j][k] - coef * ans[i][k] % mod + mod) % mod;
                }
            }
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> ans(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[i][j] = (a[i][j] % mod + mod) % mod;
        }
    }
    if (!gauss_inv(a, n, ans))
    {
        cout << "No Solution" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
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
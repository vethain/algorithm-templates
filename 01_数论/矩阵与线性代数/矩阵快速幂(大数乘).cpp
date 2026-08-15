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
const int N = 2;
const double eps = 1e-9;
struct matrix
{
    int m[N][N];
};
int nsz;
inline matrix operator*(const matrix &a, const matrix &b)
{
    matrix c;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 0; i < nsz; i++)
    {
        for (int k = 0; k < nsz; k++)
        {
            if (a.m[i][k] == 0) continue;
            for (int j = 0; j < nsz; j++)
            {
                c.m[i][j] = (c.m[i][j] + (i128)a.m[i][k] * b.m[k][j]);
                if (c.m[i][j] > mod)
                {
                    c.m[i][j] %= mod;
                }
            }
        }
    }
    return c;
}

matrix pow_matrix(matrix a, int n)
{
    matrix ans;
    memset(ans.m, 0, sizeof(ans.m));
    for (int i = 0; i < nsz; i++)
    {
        ans.m[i][i] = 1;
    }
    while (n)
    {
        if (n & 1)
        {
            ans = ans * a;
        }
        a = a * a;
        n >>= 1;
    }
    return ans;
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
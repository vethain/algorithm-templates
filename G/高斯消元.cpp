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
const int N = 5e5 + 5;
const double eps = 1e-9;
double a[105][105];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) // 原矩阵 + 增广矩阵
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cin >> a[i][j];
        }
    }
    int nwline = 1;
    for (int i = 1; i <= n; i++)
    {
        int max_row = nwline; // 主元
        for (int j = nwline + 1; j <= n; j++)
        {
            if (fabs(a[j][i]) > fabs(a[max_row][i])) // 浮点数的绝对值
            {
                max_row = j;
            }
        }
        if (fabs(a[max_row][i]) < eps) // 这一列没有主元
        {
            continue;
        }
        swap(a[nwline], a[max_row]);
        double div = a[nwline][i];
        for (int j = i; j <= n + 1; j++)
        {
            a[nwline][j] /= div;
        }
        for (int j = 1; j <= n; j++)
        {
            if (j != nwline)
            {
                double temp = a[j][i];
                for (int k = i; k <= n + 1; k++)
                {
                    a[j][k] -= temp * a[nwline][k];
                }
            }
        }
        // 一列一列处理，保证每一列1 0 0 0 .... 同时，由于处理到某一列时，可以
        // 保证之前的列数除主元外都是0  那么可以保证之前是0的项不会被改变
        nwline++;
    }
    bool t1 = false;
    bool t2 = false;
    for (int i = 1; i <= n; i++)
    {
        // 检查当前行是否所有系数都为0
        bool all_zero = true;
        for (int j = 1; j <= n; j++)
        {
            if (fabs(a[i][j]) > eps)
            {
                all_zero = false;
                break;
            }
        }
        if (all_zero)
        {
            t1 = true; // 存在全零系数行
            // 如果常数项不为0，则是矛盾方程
            if (fabs(a[i][n + 1]) > eps)
            {
                t2 = true; // 无解
            }
        }
    }
    if (t2) // 存在矛盾方程，无解
    {
        cout << -1 << endl;
    }
    else if (t1) // 存在全零行但无矛盾，无穷多解
    {
        cout << 0.00 << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "x" << i << "=" << fixed << setprecision(2) << a[i][n + 1] << endl;
        }
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
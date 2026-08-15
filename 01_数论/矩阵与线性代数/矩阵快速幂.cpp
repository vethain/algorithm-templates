#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define tos to_string
#define debug(x) cerr << #x << " : " << x << endl
using namespace std;

#define endl '\n'
#define uul __int128 // 输入输出需自定义
#define int long long int
#define ull unsigned long long int
using namespace std;

const int mod = 1e9;
const int N = 1e5 + 5;

// 斐波那契 |1 1|把这个二维矩阵应用快速幂，n次方后的(0,1) 就是斐波那契的第n + 1项
//         |1 0|
//     \(\gcd(f_n, f_m) = f_{\gcd(n, m)}\)一个重要性质
struct matrix
{
    int m[N][N]; // 根据需求对N赋值
};

inline matrix operator*(const matrix &a, const matrix &b)
{
    matrix c;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            if (a.m[i][k] == 0) continue;
            for (int j = 0; j < N; j++)
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
    for (int i = 0; i < N; i++)
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
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define i128 __int128
#define i32 int32_t
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " : " << x << endl
#define sig cerr << "OK" << endl;
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
template <typename T>
T rd(T l, T r)
{
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<T> dist(l, r);
    return dist(rng);
}
template <typename T>
bool ckmax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}
template <typename T>
bool ckmin(T &a, T b)
{
    return b < a ? (a = b, true) : false;
}

const int N = 1e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

//https://oi-wiki.org/math/combinatorics/catalan/

//下标从0开始
int fact[N];
int inv_fact[N];
int pw(int a, int b)
{
    int ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            ans = (i128)ans * a % mod;
        }
        a = (i128)a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}
void init(int n, int mod)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv_fact[n] = pw(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
}
int C(int n, int k, int mod)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}
void solve() 
{
    int n;
    cin >> n;
    vector <int> dp(n + 1), fac(2 * n + 1, 1);
    for (int i = 1; i <= n; i++) dp[i] = (i * 4 - 2) * dp[i - 1] / (i + 1);
    dp[n] = C(2 * n, n, mod) * pw(n + 1, mod - 2) % mod;
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundus
    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}

/*
# 卡特兰数总结

## 一、递推定义

卡特兰数 \(C_n\) 满足如下递推关系：

\[
C_n =
\begin{cases}
1, & n = 0, \\
\sum\limits_{i=0}^{n-1} C_i C_{n-1-i}, & n > 0.
\end{cases}
\]

其含义是：规模为 \(n\) 的问题可以通过枚举分界点，拆分为两个规模分别为 \(i\) 和 \(n-1-i\) 的子问题。

前几项为：

\[
1,\ 1,\ 2,\ 5,\ 14,\ 42,\ 132,\ 429,\ 1430,\ldots
\]

## 二、常用公式

### 1. 组合数 / 阶乘形式

\[
C_n = \frac{1}{n+1}\binom{2n}{n}
= \frac{(2n)!}{n!(n+1)!},
\quad n \ge 0.
\]

### 2. 组合数差形式

\[
C_n = \binom{2n}{n} - \binom{2n}{n+1},
\quad n \ge 0.
\]

### 3. 相邻项递推公式

\[
C_n = \frac{4n-2}{n+1} C_{n-1},
\quad n > 0,\ C_0 = 1.
\]

这三种形式都可以用于高效计算卡特兰数。

## 三、常见应用

1. **路径计数问题**  
   在 \(n \times n\) 方格图中，从左下角 \((0,0)\) 走到右上角 \((n,n)\)，每次只能向右或向上走一步，且不越过对角线 \(y=x\) 的路径数为 \(C_n\)。

2. **圆内不相交弦计数问题**  
   圆上有 \(2n\) 个点，将这些点成对连接，使得所得 \(n\) 条线段两两不相交的方案数为 \(C_n\)。

3. **三角剖分计数问题**  
   在不相交对角线的情况下，将一个凸 \((n+2)\) 边形分成三角形区域的方法数为 \(C_n\)。

4. **二叉树计数问题**  
   含有 \(n\) 个结点的形态不同的二叉树数目为 \(C_n\)。  
   等价地，含有 \(n\) 个非叶结点的形态不同的满二叉树数目也为 \(C_n\)。

5. **括号序列计数问题**  
   由 \(n\) 对括号构成的合法括号序列数为 \(C_n\)。

6. **出栈序列计数问题**  
   一个栈的进栈序列为 \(1,2,3,\ldots,n\)，其合法出栈序列的数目为 \(C_n\)。

7. **数列计数问题**  
   由 \(n\) 个 \(+1\) 和 \(n\) 个 \(-1\) 组成的数列 \(a_1,a_2,\ldots,a_{2n}\)，若所有部分和满足  
   \[
   a_1+a_2+\cdots+a_k \ge 0,\quad k=1,2,\ldots,2n,
   \]
   则这样的数列数目为 \(C_n\)。

这些应用本质上都源于卡特兰数定义中“将规模 \(n\) 拆分为两个子问题”的递归结构。
*/
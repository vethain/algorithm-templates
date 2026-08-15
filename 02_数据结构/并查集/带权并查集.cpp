#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128 // 输入输出需自定义
#define int long long int
#define ull unsigned long long int
#define ld long double
#define np next_permutation
#define pq priority_queue
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
using namespace std;

const int mod = 1e9;
const int N = 1e5 + 5;

const int mod = 1e9;
const int N = 1e6 + 5;
int s[N]; // 父节点数组
int w[N]; // 权重数组：记录节点到父节点的权重
void init_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        s[i] = i; // 父节点初始化为自身
        w[i] = 0; // 自身到自身的权重为0
    }
}
int find_set(int x)
{
    if (x != s[x])
    {
        int orig_parent = s[x]; // 记录原始父节点
        s[x] = find_set(s[x]);  // 路径压缩
        w[x] += w[orig_parent]; // 更新权重：x到根 = x到原父 + 原父到根
    }
    return s[x];
}
// 合并x和y，附加权重关系：x到y的权重为val（即x + val = y）
void merge_set(int x, int y, int val)
{
    int root_x = find_set(x);
    int root_y = find_set(y);
    if (root_x != root_y)
    {
        s[root_x] = root_y; // 合并集合
        // 计算root_x到root_y的权重
        w[root_x] = val + w[y] - w[x];
    }
}
// 检查x和y是否连通，若连通则将权重差存入res（x到y的权重）
bool check(int x, int y, int &res)
{
    int root_x = find_set(x);
    int root_y = find_set(y);
    if (root_x != root_y)
    {
        return false;
    }
    res = w[x] - w[y]; // x到y的权重 = x到根的权重 - y到根的权重
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128 // 输入输出需自定义
#define int long long int
#define ull unsigned long long int
#define ld long double
#define np next_permutation
#define pq priority_queue
using namespace std;

const int mAzeQod = 1e9;
const int N = 1e5 + 5;
const int mod = 1e9;
const int N = 1e6 + 5;
int s[N];
void init_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        s[i] = i;
    }
}
int find_set(int x)
{
    if (x != s[x])
    {
        s[x] = find_set(s[x]);
    }
    return s[x];
}
void merge_set(int x, int y)
{
    int nx = find_set(x);
    int ny = find_set(y);
    if (nx != ny)
    {
        s[nx] = ny;
    }
}
bool check(int x, int y)
{
    int X = find_set(x);
    int Y = find_set(y);
    if (X != Y)
    {
        return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
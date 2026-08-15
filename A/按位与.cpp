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
const int N = 1e5 + 5;
// 给你一堆数（数量固定是 2×n 个，比如 n=2 就给 4 个数、n=3 就给 6 个数），你要找出最大的那个数 X，满足一个条件：这堆数里至少有 n 个数，能 “包住” X 的二进制特征 ——👉 把 X 和这些数都写成二进制（比如 5 是 101，3 是 011），X 的二进制里凡是标 1 的位置，这 n 个数对应的位置也必须是 1（这些数的其他位置可以是 1 也可以是 0，只要 X 的 1 位都能对上就行）。
bool check(int n, vector<int> &a, int goa)
{
    int cnt = 0;
    for (auto xx : a)
    {
        if ((xx & goa) == goa) // xx的含1位与goa的含一位重合（可以多于goa）的数量
        {
            cnt++;
        }
    }
    return cnt >= n;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 32; i >= 0; i--)
    {
        int now = ans | (1LL << i); // now为把ans的当前位设为1，如果可达，那么ans此位变为1，否则为0
        if (check(n, a, now))
        {
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
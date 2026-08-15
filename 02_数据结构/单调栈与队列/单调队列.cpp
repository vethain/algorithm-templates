#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128 // 输入输出需自定义
#define int long long int
#define ull unsigned long long int
#define ld long double
#define np next_permutation
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
using namespace std;

const int mod = 1e9;
const int N = 1e5 + 5;
// O(n) 求固定长度的滑动窗口的最值
void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    deque<int> v;
    vector<int> b;
    for (int i = 1; i <= n; i++)
    {
        while (!v.empty() && a[v.back()] >= a[i])
        {
            v.pop_back();
        }
        v.push_back(i);
        if (i - v.front() >= n)
        {
            v.pop_front();
        }
        if (i >= n)
        {
            b.push_back(a[v.front()]);
        }
    }
    // 见LUOGU p3957
    const auto ok = [&](int x) -> bool
    {
        fl(dp, inf);
        dp[0] = 0;
        int ans = 0;
        deque<int> q;
        for (int i = 1, j = 0; i <= n; i++)
        {
            while (j < i && a[i].first - a[j].first >= d - x)
            {
                if (dp[j] != inf)
                {
                    while (!q.empty() && dp[q.back()] < dp[j])
                    {
                        q.pop_back();
                    }
                    q.push_back(j);
                }

                j++;
            }
            while (!q.empty() && a[i].first - a[q.front()].first > d + x)
            {
                q.pop_front();
            }
            if (!q.empty())
            {
                dp[i] = max(dp[i], dp[q.front()] + a[i].second);
                ans = max(ans, dp[i]);
            }
        }
        return ans >= k;
    };
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
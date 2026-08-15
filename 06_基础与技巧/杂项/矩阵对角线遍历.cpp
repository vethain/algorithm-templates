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

void solve()
{
    int n, m;
    cin >> n >> m;
    Y;
    int ans[n][m];
    int now = 1;
    int x = 0, y = 0;
    for (int i = 0; i < n + m - 1; i++)
    {
        for (int j = max(0LL, i - m + 1); j <= min(i, n - 1); j++)
        {
            ans[j][i - j] = now;
            now++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
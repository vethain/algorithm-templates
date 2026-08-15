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
const int N = 3e5 + 5;

vector<int> g[N];
void init()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            g[j].push_back(i);
        }
    }
}
void solve()
{
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

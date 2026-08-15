#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <deque>
#include <cmath>
#include <climits>
#include <cstdlib>

#define ll long long int
#define ull unsigned long long int
using namespace std;

const int N = 15;
ll dp[N], num[N];
ll cnta[N], cntb[N];

void init()
{
    for (int i = 1; i <= N; i++)
    {
        dp[i] = i * pow(10, i - 1);
    }
}
void solve(ll x, ll *cnt)
{
    int len = 0;
    while (x)
    {
        len++;
        num[len] = x % 10;
        x /= 10;
    }
    for (int i = len; i >= 1; i--)
    {
        for (int j = 0; j <= 9; j++)
        {
            cnt[j] += dp[i - 1] * num[i];
        }
        for (int j = 0; j < num[i]; j++)
        {
            cnt[j] += pow(10, i - 1);
        }
        ll num2 = 0;
        for (int j = i - 1; j >= 1; j--)
        {
            num2 = num2 * 10 + num[j];
        }
        cnt[num[i]] += num2 + 1;
        cnt[0] -= pow(10, i - 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    ll a, b;
    cin >> a >> b;
    solve(a - 1, cnta);
    solve(b, cntb);
    for (int i = 0; i <= 9; i++)
    {
        cout << cntb[i] - cnta[i] << " ";
    }
    return 0;
}
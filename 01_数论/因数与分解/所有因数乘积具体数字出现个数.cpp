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
#include <numeric>
#include <unordered_map>

#define endl '\n'
#define uul __int128 // 输入输出需自定义
#define ll long long int
#define ull unsigned long long int
using namespace std;

const ll mod = 1e9;
const ll N = 1e5 + 5;

ll cal(ll x, ll lim) // 1到lim所有因数乘积可以凑出多少个x
{
    ll num = 0;
    for (ll i = x; i <= lim; i *= x)
    {
        ll n = lim / i;
        for (ll l = 1; l <= n; l = n / (n / l) + 1)
        {
            ll r = n / (n / l);
            num += (r - l + 1) * (n / l);
        }
    }
    return num;
}
void solve()
{
    int nn = cal(48, 6);
    cout << nn << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
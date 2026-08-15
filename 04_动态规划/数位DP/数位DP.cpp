#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 1000000000000000000LL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
template <typename T, size_t SIZE>
void fl(T (&arr)[SIZE], const T &val)
{
    fill(arr, arr + SIZE, val);
}
template <typename Container>
void fl(Container &container, const typename Container::value_type &val)
{
    fill(container.begin(), container.end(), val);
}

const int N = 15;
const double eps = 1e-9;
int mod = 1e9 + 7;

int dp[N], ten[N];
vector<int> c1(10), c2(10);
void init()
{
    ten[0] = 1;
    dp[0] = 0;
    for (int i = 1; i < N; i++)
    {
        ten[i] = ten[i - 1] * 10;
        dp[i] = dp[i - 1] * 10 + ten[i - 1];
    }
}
void get(int a, vector<int> &c1)
{
    int num[N];
    int cnt = 0;
    while (a)
    {
        num[++cnt] = a % 10;
        a /= 10;
    }
    for (int i = cnt; i > 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            c1[j] += dp[i - 1] * num[i];
        }
        for (int j = 0; j < num[i]; j++)
        {
            c1[j] += ten[i - 1];
        }
        int sum = 0;
        for (int j = i - 1; j > 0; j--)
        {
            sum *= 10;
            sum += num[j];
        }
        c1[num[i]] += sum + 1;
        c1[0] -= ten[i - 1];
    }
}
void solve()
{
    int a, b;
    cin >> a >> b;
    get(b, c1);
    get(a - 1, c2);
    for (int i = 0; i < 10; i++)
    {
        cout << c1[i] - c2[i] << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundus
    init();
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}